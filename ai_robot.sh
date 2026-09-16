#!/bin/bash

echo "Opening AI Robot terminals..."

# Start Ollama only when its local API is not already available.
if ! curl --silent --fail http://127.0.0.1:11434/api/tags >/dev/null; then
	nohup ollama serve >> /home/ojith/ollama.log 2>&1 &
	sleep 3
fi

# 1 - Robot Controller
ptyxis --new-window -- bash -c '
cd ~/ros2_ws
source /opt/ros/lyrical/setup.bash
source ~/ros2_ws/install/setup.bash
echo "===== ROBOT CONTROLLER ====="
ros2 run robot_car robot_controller_node
echo "Robot Controller stopped."
exec bash
' &

sleep 2


# 2 - Computer Vision
ptyxis --new-window -- bash -c '
cd ~/ros2_ws
source /opt/ros/lyrical/setup.bash
source ~/ros2_ws/install/setup.bash
export PYTHONPATH=~/ros2_ws/src/robot_car/venv/lib/python3.14/site-packages:$PYTHONPATH
echo "===== COMPUTER VISION ====="
ros2 run robot_car computer_vision_engine_node
echo "Computer Vision stopped."
exec bash
' &

sleep 2


# 3 - Behaviour Controller
ptyxis --new-window -- bash -c '
cd ~/ros2_ws
source /opt/ros/lyrical/setup.bash
source ~/ros2_ws/install/setup.bash
export PYTHONPATH=~/ros2_ws/src/robot_car/venv/lib/python3.14/site-packages:$PYTHONPATH
echo "===== BEHAVIOUR CONTROLLER ====="
ros2 run robot_car behaviour_controller_node
echo "Behaviour Controller stopped."
exec bash
' &

sleep 2


# 4 - Display Node
ptyxis --new-window -- bash -c '
cd ~/ros2_ws
source /opt/ros/lyrical/setup.bash
source ~/ros2_ws/install/setup.bash
echo "===== DISPLAY NODE ====="
ros2 run robot_car display_node
echo "Display Node stopped."
exec bash
' &

sleep 2


# # 5 - Audio Node
ptyxis --new-window -- bash -c '
cd ~/ros2_ws
source /opt/ros/lyrical/setup.bash
source ~/ros2_ws/install/setup.bash
echo "===== AUDIO NODE ====="
ros2 run robot_car audio_node
echo "Audio Node stopped."
exec bash
' &

sleep 2


# 6 - Voice STT/TTS
# ptyxis --new-window -- bash -c '
# cd ~/ros2_ws
# source /opt/ros/lyrical/setup.bash
# source ~/ros2_ws/install/setup.bash
# export PYTHONPATH=~/ros2_ws/src/robot_car/venv/lib/python3.14/site-packages:$PYTHONPATH
# echo "===== VOICE STT/TTS ====="
# ros2 run robot_car voice_node --ros-args \
# 	-p vosk_model_path:=$HOME/ros2_ws/models/vosk-model-small-en-us-0.15 \
# 	-p sample_rate:=44100 \
# 	-p ollama_model:=gemma3:1b
# echo "Voice STT/TTS stopped."
# exec bash
# ' &

# sleep 2

# # 7 - RQT Graph
# ptyxis --new-window -- bash -c '
# cd ~/ros2_ws
# source /opt/ros/lyrical/setup.bash
# source ~/ros2_ws/install/setup.bash
# echo "===== RQT GRAPH ====="
# ros2 run rqt_graph rqt_graph
# echo "RQT Graph stopped."
# exec bash
# ' &

echo "All terminals launched."
