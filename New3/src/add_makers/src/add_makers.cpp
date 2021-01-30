#include <ros/ros.h>
#include <cmath>
#include <visualization_msgs/Marker.h>
#include "nav_msgs/Odometry.h"
using namespace std;

double ro_x, ro_y;
double m_x, m_y;
double p_error = 10;
nav_msgs::Odometry pose_msg;
visualization_msgs::Marker marker;

double xStart = -2.4, yStart = 0.23;
double xEnd = 0.2, yEnd = -2.3;
void od_call(const nav_msgs::Odometry::ConstPtr& odom_msg){
  pose_msg = *odom_msg;
  ro_x = pose_msg.pose.pose.position.x;
  ro_y = pose_msg.pose.pose.position.y;
}




int main( int argc, char** argv )
{
  ros::init(argc, argv, "basic_shapes");
  ros::NodeHandle n;
  ros::Rate r(1);
  bool end_marker = false;
  bool initial_marker = true;
  bool startReached = false;
  bool endReached = false;


   p_error = pow(ro_x - m_x,2) + pow(ro_y - m_y,2);
    ROS_INFO("The position error, %5.2f", p_error);
    ROS_INFO("The robot position, %5.2f, %5.2f", ro_x, ro_y);

  ros::Subscriber odom_subscriber;
  odom_subscriber = n.subscribe("/odom", 10, od_call);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);


 marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();


  marker.ns = "basic_shapes";
  marker.id = 0;

  marker.type = visualization_msgs::Marker::CUBE;
 
  
    marker.action = visualization_msgs::Marker::ADD;
 
 
  marker.pose.position.x = xStart;
  marker.pose.position.y = yStart;
  marker.pose.position.z = 0.1;
 
  marker.pose.orientation.w = 1.0;
  marker.scale.x = 0.1;
  marker.scale.y = 0.1;
  marker.scale.z = 0.1;
  marker.color.r = 0.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;
  marker.lifetime = ros::Duration();

  m_x = marker.pose.position.x;
  m_y = marker.pose.position.y;


  
  while (marker_pub.getNumSubscribers() < 1){
      if (!ros::ok()){return 0;}
      sleep(1);}
  marker_pub.publish(marker);

  ros::Duration(5.0).sleep();

  marker.action = visualization_msgs::Marker::DELETE;
  
  while (marker_pub.getNumSubscribers() < 1){
      if (!ros::ok()){return 0;}
      sleep(1);}
  marker_pub.publish(marker);
  ros::Duration(5.0).sleep();



  marker.type = visualization_msgs::Marker::CUBE;
 
  
  marker.action = visualization_msgs::Marker::ADD;
 
  
 
  marker.pose.position.x = xEnd;
  marker.pose.position.y = yEnd;
  marker.pose.position.z = 0.1;
 
  marker.pose.orientation.w = 1.0;


  marker.lifetime = ros::Duration();

  m_x = marker.pose.position.x;
  m_y = marker.pose.position.y;

  
  while (marker_pub.getNumSubscribers() < 1){
    if (!ros::ok()){return 0;}
    sleep(1);}
  marker_pub.publish(marker);

  ros::spinOnce();
  ros::Duration(0.5).sleep();
    

  return 0;


}
