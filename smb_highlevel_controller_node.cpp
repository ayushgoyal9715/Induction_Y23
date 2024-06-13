#include <ros/ros.h>
#include "smb_highlevel_controller/SmbHighlevelController.hpp"
#include <sensor_msgs/LaserScan.h> 

void scannerCallback(const sensor_msgs::LaserScan::ConstPtr& msg) {
    // Log that the callback was triggered
    ROS_INFO("scannerCallback triggered");

    std::vector<float> ranges = msg->ranges;

    // Check if the ranges vector is empty
    if (ranges.empty()) {
        ROS_WARN("Received an empty ranges vector.");
        return;
    }

    float min_distance = ranges[0];

    // Loop through the ranges array starting from the second element
    for (size_t i = 1; i < ranges.size(); i++) {
        if (ranges[i] < min_distance) {
            min_distance = ranges[i];
        }
    }

    ROS_INFO("Smallest distance = %f", min_distance);
}

int main(int argc, char** argv) {
    // Initialize the ROS node
    ros::init(argc, argv, "smb_highlevel_controller");

    // Create a NodeHandle
    ros::NodeHandle nodeHandle("~");

    // Log that the node has started
    ROS_INFO("smb_highlevel_controller node started");

    // Define the topic name (e.g., /scan)
    std::string topic = "/scan";

    // Subscribe to the LaserScan topic
    ros::Subscriber subscriber = nodeHandle.subscribe(topic, 100, scannerCallback);

    // Initialize the SmbHighlevelController class (assuming it's correctly implemented elsewhere)
    smb_highlevel_controller::SmbHighlevelController smbHighlevelController(nodeHandle);

    // Spin to keep the node running and processing callbacks
    ros::spin();

    return 0;
}

