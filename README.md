First ROS 2 Robot

My first ROS 2 mobile robot project using:

    Raspberry Pi 5
    Ubuntu 26.04
    ROS 2 Lyrical Luth
    Arduino motor controller
    USB camera
    Keyboard teleoperation

ROS 2 Packages

    robot_car – robot motor controller
    teleop_interface – keyboard teleoperation
    usb_cam – USB camera support


Build

cd ~/ros2_ws
colcon build --symlink-install
source /opt/ros/lyrical/setup.bash
source install/setup.bash
ros2 run robot_car robot_controller_node
ros2 run robot_car teleop_robot_node


This one will automatically run and it requires network.
Manual exe 
chmod +x ~/ai_robot.sh
export ANTHROPIC_API_KEY="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"
~/ai_robot.sh

and stop the ROS
pkill -f "ros2 run robot_car"
