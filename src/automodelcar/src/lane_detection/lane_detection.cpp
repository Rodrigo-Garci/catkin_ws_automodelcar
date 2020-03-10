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
using namespace cv;

int image_height;
int image_width;
bool line_found;
bool right_line_found;
bool left_line_found;
int steering;

class lane_detection
{
	ros::NodeHandle nh_;
	ros::Publisher pubMsg, pubDir, pubVel;
	ros::Publisher pub_steering_;
	ros::Publisher pub_speed_;
	image_transport::ImageTransport it_;
	image_transport::Subscriber sub_image_;
	image_transport::Publisher pub_image_;
    std_msgs::Int16 comm_steering_;
    std_msgs::Int16 comm_speed_;


public:
	lane_detection() : it_(nh_)
	{
		//Subscriber
		sub_image_ = it_.subscribe("/image_processed", 1,
									 &lane_detection::image_CallBack, this);

		//Publisher
		pubMsg = nh_.advertise<automodelcar::Lane>("/lane_detection",1);
		pub_steering_= nh_.advertise<std_msgs::Int16>("/manual_control/steering", 1); 
   		pub_speed_= nh_.advertise<std_msgs::Int16>("/manual_control/speed", 1);
	}

	void image_CallBack(const sensor_msgs::ImageConstPtr& msg)
	{
		cv_bridge::CvImagePtr cv_ptr;

		cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::MONO8);

		start_time = cv::getTickCount();

		cv:: Mat image;
		cv::Vec4f line;
		std::vector<cv::Point> lane_centers;
		std::vector<cv::Point> left_line_points;
		std::vector<cv::Point> right_line_points;

		//Shape extraction and image reallocator
		image = cv_ptr-> image;
		image_height = image.size().height;
		image_width = image.size().width;

		VideoWriter video("outcpp.avi",CV_FOURCC('M','J','P','G'),10, Size(640,480));
		video.write(image);
		destroyAllWindows();

/*
		//Filling the black corners
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
*/
		//Image filtering blur applicance
		medianBlur(image, image, FILTER_KERNEL_SIZE);

		//Lane detection algorithm in the lane_detection.h header
		LineDetection(image, image_height, image_width, lane_centers,
		 				right_line_points, left_line_points);

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

			comm_steering_.data = ServoSaturation(CalculateServoPWM(curvature_degree,
														center_deviation,
														last_center_deviation),
														comm_steering_.data);
		}

		automodelcar::Lane LaneMsg;
		LaneMsg.header.stamp = ros::Time::now();
		LaneMsg.lane_angle = curvature_degree;
		pubMsg.publish(LaneMsg);

		comm_speed_.data = (int)-400;
		pub_speed_.publish(comm_speed_);
		pub_steering_.publish(comm_steering_);
		if(curvature_degree >= 95)
		{
			comm_steering_.data = (int)170;
			pub_steering_.publish(comm_steering_);
		}
		else if(curvature_degree <= 85)
		{
			comm_steering_.data = (int)10;
			pub_steering_.publish(comm_steering_);
		}
		else{
			comm_steering_.data = (int)120;
			pub_steering_.publish(comm_steering_);
		}

		end_time = cv::getTickCount();
		elapsed_time = (end_time - start_time)/cv::getTickFrequency();

		if (DEBUG)
		{
			// Print debug info 
			ROS_INFO(" devistion from center = %i", center_deviation);
			ROS_INFO(" curvature_degree = %i", curvature_degree);
			ROS_INFO(" steering_PWM = %i", comm_steering_.data);
			ROS_INFO(" speed_PWM =  %i", comm_speed_.data);
			cout << " right_lane = " << right_line_found << std::endl;
			cout << " left_lane = " << left_line_found << std::endl;
			ROS_INFO(" frame time: %.4f ----- block end\n", elapsed_time);
			cv::imshow(LANE_DETECTION_WINDOW, image);
			cv::waitKey(3); 			
		}

		

	}
};

int main(int argc, char** argv)
{
	//Inicializar el nodo ROS
	ros::init(argc, argv, "lane_detection");
	ROS_INFO("RUNNING LINE DETECTION NODE ...");

	comm_steering_.data = SERVO_CENTER;

	lane_detection ld;
	ros::spin();
	return 0;
}