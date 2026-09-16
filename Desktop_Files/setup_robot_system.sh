
#!/bin/bash

set -e

echo "=============================="
echo " Raspberry Pi 5 ROS2 Robot Setup"
echo "=============================="


#################################
# Install packages
#################################

sudo apt update

sudo apt install -y \
hostapd \
dnsmasq \
python3-flask \
python3-pip \
ros-jazzy-usb-cam \
ros-jazzy-rosbridge-suite \
iw


#################################
# Create folders
#################################

mkdir -p ~/robot_web/templates

cd ~/ros2_ws/src


if [ ! -d "robot_control" ]; then

ros2 pkg create robot_control \
--build-type ament_python

fi


#################################
# WIFI AP CONFIG
#################################

sudo systemctl unmask hostapd || true


sudo bash -c 'cat > /etc/hostapd/hostapd.conf' <<CONF

interface=uap0
driver=nl80211

ssid=Robot_AP

hw_mode=g
channel=6

wpa=2
wpa_passphrase=Robot12345

wpa_key_mgmt=WPA-PSK
rsn_pairwise=CCMP

CONF


sudo bash -c 'echo DAEMON_CONF="/etc/hostapd/hostapd.conf" > /etc/default/hostapd'


sudo mv /etc/dnsmasq.conf /etc/dnsmasq.conf.backup 2>/dev/null || true


sudo bash -c 'cat > /etc/dnsmasq.conf' <<CONF

interface=uap0

dhcp-range=192.168.4.10,192.168.4.100,255.255.255.0,24h

CONF



#################################
# AP START SCRIPT
#################################

cat > ~/ap_start.sh <<'SCRIPT'

#!/bin/bash

sudo iw dev wlan0 interface add uap0 type __ap || true

sudo ip addr add 192.168.4.1/24 dev uap0 || true

sudo ip link set uap0 up

sudo systemctl restart dnsmasq

sudo systemctl restart hostapd

SCRIPT


chmod +x ~/ap_start.sh



#################################
# ROS2 MOTOR NODE
#################################

cd ~/ros2_ws/src/robot_control/robot_control


cat > motor_node.py <<'PY'

import rclpy

from rclpy.node import Node

from geometry_msgs.msg import Twist



class MotorNode(Node):

    def __init__(self):

        super().__init__('motor_node')

        self.sub=self.create_subscription(
            Twist,
            '/cmd_vel',
            self.callback,
            10
        )


    def callback(self,msg):

        print(
        "Linear:",
        msg.linear.x,
        "Angular:",
        msg.angular.z
        )

        # Add L298N GPIO control here



def main():

    rclpy.init()

    node=MotorNode()

    rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()



if __name__=="__main__":

    main()

PY



cd ~/ros2_ws/src/robot_control

python3 - <<EOF

from pathlib import Path

p=Path("setup.py")

s=p.read_text()

s=s.replace(
"entry_points={",
"entry_points={'console_scripts':['motor_node = robot_control.motor_node:main'],},\\n\\n#"
)

p.write_text(s)

