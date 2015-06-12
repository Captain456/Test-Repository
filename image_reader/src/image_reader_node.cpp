#include "opencv2/opencv.hpp"
#include <iostream>
#include <ros/ros.h>
#include "sensor_msgs/Image.h"
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

using namespace cv;

void call_back(const sensor_msgs::ImageConstPtr& msg) {

    cv_bridge::CvImagePtr cv_ptr;
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
    
    namedWindow("please", CV_WINDOW_AUTOSIZE);
    imshow("please", cv_ptr->image);
    waitKey(5); 
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "image_reader_node");
    ros::NodeHandle n;
    ros::Subscriber s = n.subscribe<sensor_msgs::Image>("/camera/rgb/image_raw", 10, call_back);
    
    while(ros::ok)
        ros::spin();

    return 0;
}

