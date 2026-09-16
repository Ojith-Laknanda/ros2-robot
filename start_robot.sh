

#!/bin/bash


source /opt/ros/jazzy/setup.bash

source ~/ros2_ws/install/setup.bash



echo "Starting AP..."

~/ap_start.sh



echo "Starting ROS bridge..."

ros2 launch rosbridge_server rosbridge_websocket_launch.xml &



echo "Starting USB Camera..."

ros2 run usb_cam usb_cam_node_exe &



echo "Starting Motor Node..."

ros2 run robot_control motor_node &



echo "Starting Web..."

sudo python3 ~/robot_web/app.py


