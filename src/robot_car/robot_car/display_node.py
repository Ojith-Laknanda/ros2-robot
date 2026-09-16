# # import subprocess
# # import rclpy
# # from rclpy.node import Node
# # from ui_interface.msg import DisplayImage


# # class DisplayNode(Node):

# #     def __init__(self):
# #         super().__init__("display_node")

# #         self.subscription = self.create_subscription(
# #             DisplayImage,
# #             "display_cmds",
# #             self.display_callback,
# #             10
# #         )

# #         self.process = None

# #         self.get_logger().info("Display node started")

# #     def display_callback(self, msg):

# #         self.get_logger().info(f"Opening {msg.image_path}")

# #         if self.process:
# #             self.process.terminate()

# #         self.process = subprocess.Popen([
# #             "pqiv",
# #             "--fullscreen",
# #             "--hide-info-box",
# #             msg.image_path
# #         ])


# # def main(args=None):

# #     rclpy.init(args=args)

# #     node = DisplayNode()

# #     rclpy.spin(node)

# #     node.destroy_node()

# #     rclpy.shutdown()


# # if __name__ == "__main__":
# #     main()


# import subprocess
# import rclpy
# from rclpy.node import Node
# from ui_interface.msg import DisplayImage


# class DisplayNode(Node):

#     def __init__(self):
#         super().__init__("display_node")

#         self.subscription = self.create_subscription(
#             DisplayImage,
#             "display_cmds",
#             self.display_callback,
#             10
#         )

#         self.process = None
#         self.current_image = ""   # <-- Remember current image

#         self.get_logger().info("Display node started")

#     def display_callback(self, msg):

#         # Do nothing if it's the same image
#         if msg.image_path == self.current_image:
#             return

#         self.get_logger().info(f"Opening {msg.image_path}")

#         # Close previous image
#         if self.process:
#             self.process.terminate()

#         # Open new image
#         self.process = subprocess.Popen([
#             "pqiv",
#             "--fullscreen",
#             "--hide-info-box",
#             msg.image_path
#         ])

#         # Save current image path
#         self.current_image = msg.image_path


# def main(args=None):

#     rclpy.init(args=args)

#     node = DisplayNode()

#     rclpy.spin(node)

#     node.destroy_node()

#     rclpy.shutdown()


# if __name__ == "__main__":
#     main()


import subprocess
import rclpy
from rclpy.node import Node
from ui_interface.msg import DisplayImage


class DisplayNode(Node):

    def __init__(self):
        super().__init__("display_node")

        self.subscription = self.create_subscription(
            DisplayImage,
            "display_cmds",
            self.display_callback,
            10
        )

        self.process = None
        self.current_image = ""   # <-- Remember current image

        self.get_logger().info("Display node started")

    def display_callback(self, msg):

        # Do nothing if it's the same image
        if msg.image_path == self.current_image:
            return

        self.get_logger().info(f"Opening {msg.image_path}")

        # Close previous image
        if self.process:
            self.process.terminate()

        # Open new image
        self.process = subprocess.Popen([
            "pqiv",
            "--fullscreen",
            "--hide-info-box",
            msg.image_path
        ])

        # Save current image path
        self.current_image = msg.image_path


def main(args=None):

    rclpy.init(args=args)

    node = DisplayNode()

    rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()