#!/bin/sh
xterm -e "source /opt/ros/kinetic/setup.bash;roscore"&
sleep 3
xterm -e "roslaunch my_robot world.launch"&
sleep 3
xterm -e "roslaunch my_robot amcl.launch" &
sleep 3
xterm -e "rosrun add_makers add_makers2"
