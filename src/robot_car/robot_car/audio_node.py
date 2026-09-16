import os
import subprocess

import rclpy
from rclpy.node import Node
from ui_interface.msg import PlayAudio


class AudioNode(Node):

    def __init__(self):
        super().__init__("audio_node")

        self.subscription = self.create_subscription(
            PlayAudio,
            "voice_cmds",
            self.audio_callback,
            10
        )

        self.process = None
        self.current_audio = ""

        self.get_logger().info("Audio node started")

    def audio_callback(self, msg):
        audio_path = msg.audio_path

        if not audio_path:
            return

        if audio_path == self.current_audio:
            return

        if not os.path.isfile(audio_path):
            self.get_logger().error(f"Audio file not found: {audio_path}")
            return

        if self.process is not None:
            self.process.terminate()

        self.get_logger().info(f"Playing: {audio_path}")

        self.process = subprocess.Popen([
            "mpg123",
            "-q",
            audio_path
        ])

        self.current_audio = audio_path


def main(args=None):
    rclpy.init(args=args)

    node = AudioNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if node.process is not None:
            node.process.terminate()

        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
