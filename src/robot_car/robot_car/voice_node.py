import json
import os
import queue
import subprocess
import threading
import urllib.error
import urllib.request

import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class VoiceNode(Node):
    def __init__(self):
        super().__init__('voice_node')

        self.declare_parameter(
            'vosk_model_path',
            os.path.expanduser('~/ros2_ws/models/vosk-model-small-en-us-0.15'),
        )
        self.declare_parameter('sample_rate', 44100)
        self.declare_parameter('block_size', 8000)
        self.declare_parameter('input_device', 0)
        self.declare_parameter('wake_word', '')
        self.declare_parameter('ollama_url', 'http://127.0.0.1:11434/api/generate')
        self.declare_parameter('ollama_model', 'gemma3:1b')
        self.declare_parameter('speaker_device', '')
        self.declare_parameter('espeak_voice', 'en')
        self.declare_parameter('system_prompt', (
            'You are Rocky, a friendly mobile robot. Give short, simple answers. '
            'Never control motors directly and never give dangerous instructions.'
        ))

        self.text_publisher = self.create_publisher(String, 'voice_text', 10)
        self.response_publisher = self.create_publisher(String, 'voice_response', 10)
        self.say_subscription = self.create_subscription(
            String, 'voice_say', self._say_callback, 10
        )
        self._audio_queue = queue.Queue()
        self._stop_event = threading.Event()
        self._worker = threading.Thread(target=self._listen_loop, daemon=True)
        self._worker.start()

        self.get_logger().info('Voice node started: Vosk -> Ollama -> eSpeak-NG')

    def _say_callback(self, message):
        if message.data.strip():
            self._speak(message.data.strip())

    def _listen_loop(self):
        try:
            import sounddevice as sd
            from vosk import KaldiRecognizer, Model
        except ImportError as error:
            self.get_logger().error(
                'Install the voice Python packages with: '
                f'python3 -m pip install vosk sounddevice ({error})'
            )
            return

        model_path = self.get_parameter('vosk_model_path').value
        if not os.path.isdir(model_path):
            self.get_logger().error(
                f'Vosk model directory does not exist: {model_path}'
            )
            return

        sample_rate = int(self.get_parameter('sample_rate').value)
        block_size = int(self.get_parameter('block_size').value)
        input_device = int(self.get_parameter('input_device').value)
        recognizer = KaldiRecognizer(Model(model_path), sample_rate)

        def audio_callback(indata, frames, time_info, status):
            if status:
                self.get_logger().warning(f'Audio input status: {status}')
            self._audio_queue.put(bytes(indata))

        try:
            with sd.RawInputStream(
                device=input_device,
                samplerate=sample_rate,
                blocksize=block_size,
                dtype='int16',
                channels=1,
                callback=audio_callback,
            ):
                self.get_logger().info(f'Listening on USB microphone device {input_device}')
                while rclpy.ok() and not self._stop_event.is_set():
                    data = self._audio_queue.get()
                    if not recognizer.AcceptWaveform(data):
                        continue
                    result = json.loads(recognizer.Result())
                    text = result.get('text', '').strip()
                    if text:
                        self._handle_text(text)
        except Exception as error:
            self.get_logger().error(f'Microphone/Vosk error: {error}')

    def _handle_text(self, text):
        self.get_logger().info(f'Heard: {text}')
        message = String()
        message.data = text
        self.text_publisher.publish(message)

        wake_word = self.get_parameter('wake_word').value.strip().lower()
        if wake_word and wake_word not in text.lower():
            return

        prompt = text
        if wake_word:
            prompt = text.lower().replace(wake_word, '', 1).strip()
        if not prompt:
            self._speak('Yes, I am listening.')
            return

        reply = self._ask_ollama(prompt)
        if reply:
            response = String()
            response.data = reply
            self.response_publisher.publish(response)
            self._speak(reply)

    def _ask_ollama(self, prompt):
        payload = json.dumps({
            'model': self.get_parameter('ollama_model').value,
            'prompt': prompt,
            'system': self.get_parameter('system_prompt').value,
            'stream': False,
        }).encode('utf-8')
        request = urllib.request.Request(
            self.get_parameter('ollama_url').value,
            data=payload,
            headers={'Content-Type': 'application/json'},
        )
        try:
            with urllib.request.urlopen(request, timeout=120) as response:
                result = json.loads(response.read().decode('utf-8'))
            return result.get('response', '').strip()
        except (urllib.error.URLError, TimeoutError, json.JSONDecodeError) as error:
            self.get_logger().error(f'Ollama request failed: {error}')
            self._speak('Sorry, I cannot reach Ollama right now.')
            return ''

    def _speak(self, text):
        command = ['espeak-ng', '-v', self.get_parameter('espeak_voice').value]
        speaker_device = self.get_parameter('speaker_device').value.strip()
        if speaker_device:
            command.extend(['-d', speaker_device])
        command.append(text)
        try:
            subprocess.run(command, check=True, timeout=60)
        except (FileNotFoundError, subprocess.SubprocessError) as error:
            self.get_logger().error(f'eSpeak-NG/USB speaker error: {error}')

    def destroy_node(self):
        self._stop_event.set()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = VoiceNode()
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, rclpy.executors.ExternalShutdownException):
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()