
#!/bin/bash

set -e


echo "Installing packages..."

sudo apt update

sudo apt install -y \
hostapd \
dnsmasq \
iw \
python3-flask \
ros-kilted-usb-cam \
ros-kilted-rosbridge-suite


pip3 install roslibpy --break-system-packages



echo "Creating WiFi AP..."


sudo systemctl unmask hostapd || true


sudo bash -c 'cat > /etc/hostapd/hostapd.conf' <<CONF

interface=wlan0
driver=nl80211

ssid=Robot_AP

hw_mode=g
channel=6

wpa=2
wpa_passphrase=Robot12345

wpa_key_mgmt=WPA-PSK
rsn_pairwise=CCMP

CONF


sudo bash -c 'echo DAEMON_CONF=/etc/hostapd/hostapd.conf > /etc/default/hostapd'



sudo mv /etc/dnsmasq.conf /etc/dnsmasq.conf.backup 2>/dev/null || true


sudo bash -c 'cat > /etc/dnsmasq.conf' <<CONF

interface=wlan0

dhcp-range=192.168.4.10,192.168.4.100,255.255.255.0,24h

CONF



echo "Setting AP IP..."


sudo ip addr add 192.168.4.1/24 dev wlan0 || true



echo "Creating ROS2 robot package..."


mkdir -p ~/ros2_ws/src

cd ~/ros2_ws/src


if [ ! -d robot_control ]; then

ros2 pkg create robot_control \
--build-type ament_python

fi



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


if __name__=="__main__":

    main()

PY



cd ~/ros2_ws

colcon build



echo "Creating web controller..."


mkdir -p ~/robot_web/templates



cat > ~/robot_web/app.py <<'PY'


from flask import Flask,render_template

import roslibpy


app=Flask(__name__)



ros=roslibpy.Ros(
host="localhost",
port=9090
)

ros.run()



cmd=roslibpy.Topic(
ros,
"/cmd_vel",
"geometry_msgs/msg/Twist"
)



@app.route("/")
def index():

    return render_template("index.html")



@app.route("/move/<direction>")
def move(direction):


    msg={

    "linear":{
    "x":0,
    "y":0,
    "z":0
    },

    "angular":{
    "x":0,
    "y":0,
    "z":0
    }

    }



    if direction=="forward":
        msg["linear"]["x"]=1


    elif direction=="backward":
        msg["linear"]["x"]=-1


    elif direction=="left":
        msg["angular"]["z"]=1


    elif direction=="right":
        msg["angular"]["z"]=-1



    cmd.publish(
    roslibpy.Message(msg)
    )


    return "OK"



app.run(
host="0.0.0.0",
port=80
)


PY




cat > ~/robot_web/templates/index.html <<'HTML'


<html>

<body>


<h1>ROS2 Robot Controller</h1>


<button onclick="fetch('/move/forward')">
Forward
</button>


<button onclick="fetch('/move/backward')">
Backward
</button>


<br><br>


<button onclick="fetch('/move/left')">
Left
</button>


<button onclick="fetch('/move/right')">
Right
</button>



</body>

</html>


HTML



echo "Creating startup script..."



cat > ~/start_robot.sh <<'SCRIPT'


#!/bin/bash


source /opt/ros/kilted/setup.bash

source ~/ros2_ws/install/setup.bash



echo "Starting WiFi AP"

sudo systemctl restart dnsmasq

sudo systemctl restart hostapd



echo "Starting ROS bridge"

ros2 launch rosbridge_server rosbridge_websocket_launch.xml &



echo "Starting USB camera"

ros2 run usb_cam usb_cam_node_exe &



echo "Starting motor node"

ros2 run robot_control motor_node &



echo "Starting web controller"

sudo python3 ~/robot_web/app.py


SCRIPT



chmod +x ~/start_robot.sh



echo ""
echo "============================"
echo "SETUP COMPLETE"
echo "============================"
echo ""
echo "Run:"
echo "~/start_robot.sh"
echo ""
echo "WiFi:"
echo "SSID: Robot_AP"
echo "Password: Robot12345"
echo ""
echo "Open:"
echo "http://192.168.4.1"
echo ""

