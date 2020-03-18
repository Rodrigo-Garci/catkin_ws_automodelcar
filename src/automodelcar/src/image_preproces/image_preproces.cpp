// 05/03/2020
#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>

// Wrap perspective points
int a = 280, b = 280, c = 43, d = 43;
// Resize dimensions
float scale_x = 0.4, scale_y = 1.2;
// Cropping image size
int startX=0,startY=90,width=640,height=350;

class image_preproces
{
	ros::NodeHandle nh_;
	image_transport::ImageTransport it_;
	image_transport::Subscriber sub_image_;
	image_transport::Publisher pub_image_;

public:
	image_preproces() : it_(nh_)
	{
		//Subcribers
		sub_image_ = it_.subscribe("/app/camera/rgb/image_raw", 1,
			&image_preproces::image_CallBack, this);

		//Publishers
		pub_image_ = it_.advertise("/image_processed", 1);
	}

void image_CallBack(const sensor_msgs::ImageConstPtr& msg)
	{
		cv_bridge::CvImagePtr cv_ptr;
		try
		{
			cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
		}

		catch ( cv_bridge::Exception& e)
		{
			ROS_ERROR("cv_bridge Exception: %s", e.what());
			return;
		}

		cv::Mat image = cv_ptr-> image, image_cropped, image_scaled, image_scaled_gray,
						image_lambda, image_wrapped;

		std::string camera = "RGB IMAGE";
		cv::imshow(camera, image);
		cv::waitKey(3);

		// Region of interest (Where the road predomine)
		cv::Rect ROI(startX, startY, width, height);
		image_cropped = image(ROI);

		// Image Resizing
		cv::resize(image_cropped, image_scaled, cv::Size(), scale_x, scale_y, CV_INTER_LINEAR);

		// Transform the RGB image to GRAY scale
		cv::cvtColor(image_scaled, image_scaled_gray, CV_BGR2GRAY);

		// Point used for homology in the perspective transform
		cv::Point2f image_points[4], object_points[4];

		// Get the image size
		int image_width = image_scaled_gray.size().width;
		int image_height = image_scaled_gray.size().height;

	    object_points[0].x = 0; 
	    object_points[0].y = a;
	    object_points[1].x = image_width;
	    object_points[1].y = b;
	    object_points[2].x = 0;
	    object_points[2].y = image_height;
	    object_points[3].x = image_width;
	    object_points[3].y = image_height;

	    image_points[0].x = 0;
	    image_points[0].y = 0;
	    image_points[1].x = image_width;
	    image_points[1].y = 0; 
	    image_points[2].x = image_width/2 - c;	//////////////
	    image_points[2].y = image_height;
	    image_points[3].x = image_width/2 + d;	//////////////
	    image_points[3].y = image_height;



		// Obtain the a matrix transform 3x3
		image_lambda = cv::getPerspectiveTransform(object_points, image_points);

		// Image Wrapping
		cv::warpPerspective(image_scaled_gray, image_wrapped,
							image_lambda, image_scaled_gray.size());

		cv_bridge::CvImage out_msg;
		out_msg.header = msg->header;
		out_msg.encoding = sensor_msgs::image_encodings::MONO8;
		out_msg.image = image_wrapped;
		pub_image_.publish(out_msg.toImageMsg());
	}

};



int main(int argc, char** argv)
{
	//Inicializar el nodo ROS
	ros::init(argc, argv, "image_preproces");
	ROS_INFO("RUNNING PREPROCESS NODE ...");

	image_preproces ip;
	ros::spin();
	return 0;
}