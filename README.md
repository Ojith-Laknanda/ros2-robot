# First ROS 2 Robot

My first ROS 2 mobile robot project using:

- Raspberry Pi 5
- Ubuntu 26.04
- ROS 2 Lyrical Luth
- Arduino motor controller
- USB camera
- Keyboard teleoperation

## ROS 2 Packages

- `robot_car` – robot motor controller
- `teleop_interface` – keyboard teleoperation
- `usb_cam` – USB camera support

## Build

```bash
cd ~/ros2_ws
colcon build --symlink-install
source /opt/ros/lyrical/setup.bash
source install/setup.bash

ros2 run robot_car robot_controller_node

ros2 run robot_car teleop_robot_node
