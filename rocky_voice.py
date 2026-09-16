import os
import json
import queue
import time
import subprocess
import urllib.error
import urllib.request
import sounddevice as sd

from vosk import Model, KaldiRecognizer

MODEL_PATH = "/home/ojith/ros2_ws/models/vosk-model-small-en-us-0.15"
OLLAMA_URL = os.getenv("OLLAMA_URL", "http://127.0.0.1:11434/api/generate")
OLLAMA_MODEL = os.getenv("OLLAMA_MODEL", "gemma3:1b")
OLLAMA_NUM_CTX = int(os.getenv("OLLAMA_NUM_CTX", "512"))
OLLAMA_NUM_PREDICT = int(os.getenv("OLLAMA_NUM_PREDICT", "64"))
SAMPLE_RATE = 44100
RECORD_SECONDS = 5
REPLY_AUDIO = "/tmp/rocky_reply.wav"

vosk_model = Model(MODEL_PATH)


def speak(text):
    print("Rocky:", text)

    subprocess.run(["espeak-ng", "-w", REPLY_AUDIO, text], check=False)
    subprocess.run(["aplay", REPLY_AUDIO], check=False)


def wait_for_wake_word():
    audio_queue = queue.Queue()
    recognizer = KaldiRecognizer(vosk_model, SAMPLE_RATE)

    def callback(indata, frames, time_info, status):
        audio_queue.put(bytes(indata))

    print('Listening for "Hi Rocky"...')

    with sd.RawInputStream(
        samplerate=SAMPLE_RATE,
        blocksize=8000,
        dtype="int16",
        channels=1,
        callback=callback
    ):
        while True:
            data = audio_queue.get()

            if recognizer.AcceptWaveform(data):
                result = json.loads(recognizer.Result())
                text = result.get("text", "").lower()

                if text:
                    print("Heard:", text)

                if "hi rocky" in text or "hey rocky" in text:
                    return


def record_question():
    audio_queue = queue.Queue()
    recognizer = KaldiRecognizer(vosk_model, SAMPLE_RATE)

    def callback(indata, frames, time_info, status):
        audio_queue.put(bytes(indata))

    print("Listening to your question...")

    start_time = time.time()

    with sd.RawInputStream(
        samplerate=SAMPLE_RATE,
        blocksize=8000,
        dtype="int16",
        channels=1,
        callback=callback
    ):
        while time.time() - start_time < RECORD_SECONDS:
            data = audio_queue.get()
            recognizer.AcceptWaveform(data)

    result = json.loads(recognizer.FinalResult())
    return result.get("text", "").strip()


def ask_local_model(question):
    payload = json.dumps({
        "model": OLLAMA_MODEL,
        "prompt": question,
        "system": (
            "You are Rocky, a friendly mobile robot. "
            "Give short and simple answers. "
            "Never control motors directly. "
            "Never give dangerous instructions."
        ),
        "options": {
            "num_ctx": OLLAMA_NUM_CTX,
            "num_predict": OLLAMA_NUM_PREDICT,
        },
        "stream": False,
        "keep_alive": 0,
    }).encode("utf-8")

    request = urllib.request.Request(
        OLLAMA_URL,
        data=payload,
        headers={"Content-Type": "application/json"},
    )

    try:
        with urllib.request.urlopen(request, timeout=120) as response:
            result = json.loads(response.read().decode("utf-8"))
        return result.get("response", "").strip()
    except (urllib.error.URLError, TimeoutError, json.JSONDecodeError) as error:
        print("Ollama error:", error)
        return "Sorry, I cannot reach the local model right now."


while True:
    try:
        wait_for_wake_word()

        speak("Yes, I am listening.")

        question = record_question()
        print("User:", question)

        if not question:
            speak("Sorry, I did not hear you.")
            continue

        if "stop" in question.lower():
            speak("Stopping now.")
            continue

        reply = ask_local_model(question)
        speak(reply)

    except KeyboardInterrupt:
        print("Rocky voice system stopped.")
        break

    except Exception as error:
        print("Error:", error)
        speak("Sorry, I am having a technical problem.")
