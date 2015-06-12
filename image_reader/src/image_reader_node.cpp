#include "opencv2/opencv.hpp"
#include <iostream>
#include <ros/ros.h>
#include "sensor_msgs/Image.h"
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

int iLowH = 170,
    iHighH = 179,
    iLowS = 150,
    iHighS = 255,
    iLowV = 60,
    iHighV = 255;


void call_back(const sensor_msgs::ImageConstPtr& msg) {

    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;

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

        //Create trackbars in "Control" window
    cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
    cvCreateTrackbar("HighH", "Control", &iHighH, 179);

    cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    cvCreateTrackbar("HighS", "Control", &iHighS, 255);

    cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
    cvCreateTrackbar("HighV", "Control", &iHighV, 255);

    Mat imgHSV;

    cvtColor(cv_ptr->image, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

    Mat imgThresholded;

    inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); 
    //Threshold the image
      
    //morphological opening (remove small objects from the foreground)
    erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
    dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

    //morphological closing (fill small holes in the foreground)
    dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
    erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

    
    //Calculate the moments of the thresholded image
    Moments oMoments = moments(imgThresholded);

    double dM01 = oMoments.m01;
    double dM10 = oMoments.m10;
    double dArea = oMoments.m00;

    // if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
    if (dArea > 10000)
    {
        //calculate the position of the ball
        int posX = dM10 / dArea;
        int posY = dM01 / dArea;        
        
        line(cv_ptr->image, Point(posX, posY), Point(0, 0), Scalar(0,0,255), 2);
    }
    namedWindow("Control", CV_WINDOW_AUTOSIZE);
    namedWindow("Thresholded Image", CV_WINDOW_AUTOSIZE);
    imshow("Thresholded Image", imgThresholded); //show the thresholded image

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

