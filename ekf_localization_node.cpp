#include <ros/ros.h>
#include "smb_highlevel_controller/SmbHighlevelController.hpp"
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h> 
void scanCallback1(const nav_msgs::Odometry::ConstPtr& msg){
    ROS_INFO("done");
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "subs1");
    ros::NodeHandle n;
    ros::Subscriber subs1=n.subscribe("/smb_velocity_controller/odom",100,scanCallback1);
    ros::spin();
    return 0;
}
