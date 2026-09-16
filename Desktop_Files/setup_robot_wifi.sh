#!/bin/bash

set -e

echo "Updating packages..."
sudo apt update

echo "Installing packages..."
sudo apt install -y hostapd dnsmasq python3-flask python3-pip

sudo systemctl stop hostapd || true
sudo systemctl stop dnsmasq || true


echo "Creating AP interface..."
sudo iw dev wlan0 interface add uap0 type __ap || true


echo "Creating hostapd config..."

sudo bash -c 'cat > /etc/hostapd/hostapd.conf' <<EOF
interface=uap0
driver=nl80211
ssid=Robot_AP
hw_mode=g
channel=6
wpa=2
wpa_passphrase=Robot12345
wpa_key_mgmt=WPA-PSK
rsn_pairwise=CCMP
EOF


sudo sed -i 's|#DAEMON_CONF=""|DAEMON_CONF="/etc/hostapd/hostapd.conf"|' /etc/default/hostapd


echo "Creating dnsmasq config..."

sudo bash -c 'cat > /etc/dnsmasq.conf' <<EOF
interface=uap0
dhcp-range=192.168.4.10,192.168.4.50,255.255.255.0,24h
EOF


echo "Creating Flask robot webpage..."

mkdir -p ~/robot_web/templates

cat > ~/robot_web/app.py <<EOF
from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def home():
    return render_template("index.html")

app.run(host="0.0.0.0", port=80)
EOF


cat > ~/robot_web/templates/index.html <<EOF
<!DOCTYPE html>
<html>
<head>
<title>Robot Control</title>
</head>

<body>

<h1>Robot Controller</h1>

<button>Forward</button>
<button>Backward</button>
<button>Left</button>
<button>Right</button>

</body>
</html>
EOF


echo "Enabling services..."

sudo systemctl enable hostapd
sudo systemctl enable dnsmasq


sudo systemctl restart hostapd
sudo systemctl restart dnsmasq


echo "DONE"
echo "Connect to WiFi:"
echo "SSID: Robot_AP"
echo "Password: Robot12345"
echo "Web: http://192.168.4.1"
