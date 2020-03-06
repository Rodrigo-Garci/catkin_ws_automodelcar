//Version  05/03/20 
#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <cv_bridge/cv_bridge.h>  
#include <sensor_msgs/image_encodings.h>
#include <ros/console.h>
#include <iostream>
#include "std_msgs/Int16.h"
#include "automodelcar/Lane.h"
#include <LocalMaximaDetection.cpp>
#include "lane_detection.h"
#include <math.h>

using namespace std;

int image_height;
int image_width;
bool line_found;
bool right_line_found;
bool left_line_found;

class lane_detection
{
	ros::NodeHandle nh_;
	ros::Publisher pubMsg, pubDir, pubVel;
	image_transport::ImageTransport it_;
	image_transport::Subscriber sub_image_;
	image_transport::Publisher pub_image_;

public:
	lane_detection() : it_(nh_)
	{
		//Subscriber
		sub_image_ = it_.subscribe("/image_processed", 1,
									 &lane_detection::image_CallBack, this);

		//Publisher
		pubMsg = nh_.advertise<automodelcar::Lane>("/lane_detection",1);
	}

	void image_CallBack(const sensor_msgs::ImageConstPtr& msg)
	{
		cv_bridge::CvImagePtr cv_ptr;

		cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::MONO8);

		cv:: Mat image;
		cv::Vec4f line;
		std::vector<cv::Point> lane_centers;
		std::vector<cv::Point> left_line_points;
		std::vector<cv::Point> right_line_points;

		//Shape extraction and image reallocator
		image = cv_ptr-> image;
		image_height = image.size().height;
		image_width = image.size().width;

		for (int i = image_height * IMAGE_PERCENTAGE; i < image_height; i++)
		{
			for (int j = 0; j < image_width; j++)
			{
				if (image.at<uchar>(i,j) < GRAY_THRESHOLD)
				{
					image.at<uchar>(i,j) = rand()%6 + 87;
				}
			}	
		}

		//Image filtering blur applicance
		medianBlur(image, image, FILTER_KERNEL_SIZE);

		//Lane detection algorithm in the lane_detection.h header
		LineDetection(image, image_height, image_width, lane_centers,
		 				right_line_points, left_line_points);

		cv::imshow(LANE_DETECTION_WINDOW, image);
		cv::waitKey(3);

		//Curvature Calculation
		line_found  = false;
		right_line_found = false;
		left_line_found = false;

		if(right_line_points.size() > MIN_RIGHT_LINE_POINTS)
		{
			cv::fitLine(right_line_points, line, CV_DIST_L2,
						0, 0.01, 0.01);
			line_found = true;
			right_line_found = true;
		}
		else if(left_line_points.size() > MIN_LEFT_LINE_POINTS)
		{
			cv::fitLine(left_line_points, line, CV_DIST_L2,
						0, 0.01, 0.01);
			line_found = true;
			left_line_found = true;
		}

		if(line_found == true)
		{
			center_deviation = int(image_width/2) - lane_centers[1].x;
			int p1 = line[2];
			int p2 = line[3];
			int p3 = (line[2]+1)+100*line[0];
			int p4 = (line[3]+1)+100*line[1];

			if (left_line_found == true)
			{
				p3 = left_line_points.back().x;
				p4 = left_line_points.back().y;
			}

			else if(right_line_found == true)
			{
				p3 = right_line_points.back().x;
				p4 = right_line_points.back().y;
			}
			
			float dif1 = p4 - p2;
			float dif2 = p3 - p1;
			float m = dif2 / dif1;

			curvature_degree = SERVO_CENTER + int(atan(m)*180.0/M_PI);
			//cout << "curvature_degree: " << curvature_degree << endl;

			automodelcar::Lane LaneMsg;
			LaneMsg.header.stamp = ros::Time::now();
			LaneMsg.steering_value = 90;
			LaneMsg.speed_value = 0;
			LaneMsg.error = curvature_degree;
			pubMsg.publish(LaneMsg);
		}



	}
};

int main(int argc, char** argv)
{
	//Inicializar el nodo ROS
	ros::init(argc, argv, "lane_detection");
	ROS_INFO("RUNNING LINE DETECTION NODE ...");

	lane_detection ld;
	ros::spin();
	return 0;
}