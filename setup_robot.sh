
#!/bin/bash

set -e

echo "=== Updating system ==="

sudo apt update


echo "=== Installing packages ==="

sudo apt install -y hostapd dnsmasq python3-flask python3-pip iw


echo "=== Unmask hostapd ==="

sudo systemctl unmask hostapd || true

sudo systemctl enable hostapd
sudo systemctl enable dnsmasq


echo "=== Stopping services ==="

sudo systemctl stop hostapd || true
sudo systemctl stop dnsmasq || true


echo "=== Creating AP interface ==="

sudo iw dev wlan0 interface add uap0 type __ap || true


echo "=== Setting AP IP ==="

sudo ip addr add 192.168.4.1/24 dev uap0 || true

sudo ip link set uap0 up


echo "=== Creating hostapd config ==="

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


sudo bash -c 'echo "DAEMON_CONF=/etc/hostapd/hostapd.conf" > /etc/default/hostapd'


echo "=== Creating dnsmasq config ==="

sudo mv /etc/dnsmasq.conf /etc/dnsmasq.conf.backup 2>/dev/null || true


sudo bash -c 'cat > /etc/dnsmasq.conf' <<CONF

interface=uap0

dhcp-range=192.168.4.10,192.168.4.100,255.255.255.0,24h

CONF


echo "=== Creating webpage ==="

mkdir -p ~/robot_web/templates


cat > ~/robot_web/app.py <<PY

from flask import Flask, render_template

app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/forward")
def forward():
    print("FORWARD")
    return "OK"


@app.route("/backward")
def backward():
    print("BACKWARD")
    return "OK"


@app.route("/left")
def left():
    print("LEFT")
    return "OK"


@app.route("/right")
def right():
    print("RIGHT")
    return "OK"


app.run(host="0.0.0.0", port=80)

PY



cat > ~/robot_web/templates/index.html <<HTML

<!DOCTYPE html>

<html>

<head>

<title>Robot Controller</title>

<style>

button{

width:150px;
height:70px;
font-size:25px;

}

</style>

</head>


<body>


<h1>Robot Control</h1>


<a href="/forward">
<button>Forward</button>
</a>


<a href="/backward">
<button>Backward</button>
</a>


<br><br>


<a href="/left">
<button>Left</button>
</a>


<a href="/right">
<button>Right</button>
</a>


</body>

</html>

HTML



echo "=== Starting services ==="


sudo systemctl restart dnsmasq

sudo systemctl restart hostapd


echo ""
echo "================================="
echo " ROBOT WIFI READY "
echo "================================="
echo "SSID     : Robot_AP"
echo "Password : Robot12345"
echo "Web      : http://192.168.4.1"
echo ""
echo "Start webpage:"
echo "sudo python3 ~/robot_web/app.py"
echo "================================="


