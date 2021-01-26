#!/bin/sh
xterm -e "source /opt/ros/kinetic/setup.bash;roscore"&
sleep 3
xterm -e "roslaunch my_robot world.launch" &
sleep 3
xterm -e "roslaunch my_robot mapping.launch" &
sleep 3
xterm -e "rosrun teleop_twist_keyboard teleop_twist_keyboard.py"&

