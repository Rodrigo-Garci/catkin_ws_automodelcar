#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

using namespace cv;
using namespace std;

bool DEBUG = true;
bool DIRECT_CONTROL = false;
int MAX_STEERING_ANGLE_LEFT = 20;
int MAX_STEERING_ANGLE_RIGHT = 160;
int MAX_VEL = -500;
int SERVO_STEP = 3;
int LANE_WIDTH = 50;
int SERVO_CENTER = 90;
bool DRIVE_RIGHT_LANE = true;
float STEERING_SPEED_RATIO = 1.2;

/* Global Constants initialization */
int RIGHT_LINE = -1;
int LEFT_LINE = 1;
int const RIGHT_LANE_ORIGIN = 120;
int const LEFT_LANE_ORIGIN = RIGHT_LANE_ORIGIN - LANE_WIDTH;
float const IMAGE_PERCENTAGE = 0.76;
int const ROW_STEP = 4;
int const SEARCH_RANGE = 10;
int const ALLOWED_DEVIATION = LANE_WIDTH/2;
int const FILTER_KERNEL_SIZE = 5;
int const GRAY_THRESHOLD = 50;
int const MAX_PEAK_HEIGHT = 25;
int const MAX_PEAK_WIDTH = 15;
int const SAFE_MARGIN = 10;
int const SPEED_INCREASE_STEP = 8;
int const SPEED_DECREASE_STEP = 10;
float const MULTIPLY_FACTOR = MAX_VEL / 100.0;
short int const GAP = 10;
short int const MIN_RIGHT_LINE_POINTS = 8;
short int const MIN_LEFT_LINE_POINTS = 5;
int last_center_position = RIGHT_LANE_ORIGIN;

int center_deviation = 0;
int curvature_degree = SERVO_CENTER;

void LocalMaximaValidation(
    int line,
    std::vector<int> local_maxima_found,
    std::vector<cv::Point> lane_centers,
    int current_row,
    std::vector<cv::Point>& line_points,
    int& index,
    bool& point_found_flag)
  {
    int dist_to_found_point = 0;
    int peak_location;
    cv::Point found_point;

    if (!(local_maxima_found.empty()))
    {
        // Get peak location accordingly to the line
        peak_location = 
            line == RIGHT_LINE ?
            local_maxima_found.front() + index:
            local_maxima_found.back();

        // Set the first local maxima found as found point
        found_point = 
            cv::Point(peak_location, current_row);

        // Euclidian distance from last right line point to found point
        dist_to_found_point = 
            int(cv::norm(line_points.back() - found_point));

        // Point found validation through distance
        if (dist_to_found_point < ALLOWED_DEVIATION)
            { 
                // Add found point to line
                line_points.push_back(found_point);
                // Adjust row index accordingly to the found point and 
                // a search range value.
                index = line_points.back().x + line * SEARCH_RANGE;
                point_found_flag = true;
            }
        else 
            // No right line point found
            index = lane_centers.back().x;
    }
    else
    {
        // No local maxima found
        index = lane_centers.back().x;
    } 
  }

std::vector<int> LocMax_pw(std::vector<int> Vi, int pProm, int w)
//std::vector<int> LocMax(std::vector<uchar> Vi, int pP)
{
	
	//Búsqueda de máximos locales

	int Tam=Vi.size();
	std::vector<int>x,y,xProm,yProm, width;
	int j,d1,d2;
	int i=1;
	//ROS_INFO("Width: %i",Tam); 256
	while (i<Tam)
	{
		j=1;
		if ((Vi[i-1]<Vi[i])&&(Vi[i]>=Vi[i+1]))
		{	
			while ((Vi[i]==Vi[i+j])&&((i+j)<Tam))
			{
				j++;
			}
			if (Vi[i]>Vi[i+j])
			{
				x.push_back(i);
				y.push_back(Vi[i]);
			}
		}
		i+=j;
	}

	int TamM=x.size();
	int pi,fi,px,py,fx,fy,fP, pmin, fmin,P;
	xProm.erase(xProm.begin(),xProm.end());
	for (i=0;i<TamM;i++)
	{
		pi=i-1;
		fi=i+1;
		py=0;
		fy=0;
		fP=0;

		if (pi>=0)
		{	
			while ((pi>=1)&&(y[pi]<=y[i]))//
			{	
				pi--; 
			}
			py=y[pi]>y[i]? y[pi]:0;
		}
		if (fi<TamM)
		{
			while ((fi<TamM-1)&&(y[fi]<=y[i]))//
			{	
				fi++;
			}
			fy=y[fi]>y[i]? y[fi]:0;	
		}
	/////////////////////////////////////////////////////////////
		pmin=Vi[x[i]];
		fmin=Vi[x[i]];
		if ((py==0)&&(fy==0))
		{
			for (j=0;j<Tam;j++)
			{
				if (Vi[j]<pmin)
					pmin=Vi[j];		
//			ROS_INFO("j1: %i",j);
			}
			P=pmin;
			
		}
		else
		{	
			if (pi<0)
			{
				for (j=x[i];j>=0;j--)
				{
					if (Vi[j]<pmin)
						pmin=Vi[j];
				}
				
			}
			else 
			{
				for (j=x[i];j>x[pi];j--)
				{
					if (Vi[j]<pmin)
						pmin=Vi[j];			
				}
				
			}
			if (fi>=TamM-1)
			{
				for (j=x[i];j<Tam;j++)
				{
					if (Vi[j]<fmin)
					fmin=Vi[j];
				}
				
			}
			else 
			{
				for (j=x[i];j<x[fi];j++)
				{
					if (Vi[j]<fmin)
					fmin=Vi[j];
				}
				
			}
			P= pmin>fmin? pmin:fmin;
		}
		j=1;
		while (((x[i]-j)>0)&&(Vi[x[i]-j]-P>(y[i]-P)/2))
			j++;
		d1=j;
		j=1;
		while (((x[i]+j)<Tam)&&(Vi[x[i]+j]-P>(y[i]-P)/2))
			j++;
		d2=j;
		int D=d2+d1;
		if ((y[i]-P>=pProm)&&(D<w))
		{
			xProm.push_back(x[i]);
			/*ROS_INFO("w: %i",D);
			int prom=y[i]-P;
			ROS_INFO("p: %i",prom);*/
		}

	}

	//return x;
	return xProm;//
}

void LineDetection(
    cv::Mat image,
    int image_height,
	int image_width,
    std::vector<cv::Point>& lane_centers,
    std::vector<cv::Point>& right_line_points,
    std::vector<cv::Point>& left_line_points)
{
    int left_index;
	int right_index;
	int current_row;
	int lane_center;
	float dist_to_found_center; 
	bool right_line_point_found;
	bool left_line_point_found; 
    std::vector<int> image_row_vector, local_maxima_found;
    cv::Point center_found;

    // Set initial conditions
    left_index = last_center_position;
    right_index = last_center_position;
	current_row = image_height - GAP; 
	dist_to_found_center = -1.0;
	
	// Set initial line points
    lane_centers.push_back(
		cv::Point2f(last_center_position, image_height - ROW_STEP));	
    left_line_points.push_back(cv::Point2f(
		last_center_position - (LANE_WIDTH/2), image_height - ROW_STEP));
    right_line_points.push_back(cv::Point2f(
		last_center_position + (LANE_WIDTH/2), image_height - ROW_STEP));
	
	// Image scanning by rows
	while (current_row > (image_height * IMAGE_PERCENTAGE))
  	{

		/* Right side scanning */
		right_line_point_found = false;
		// Prepare image row vector to scan
		image_row_vector = 
			(std::vector<int>) image.row(current_row).colRange(right_index, image_width);
		// Search for local maxima
		local_maxima_found = 
			LocMax_pw(image_row_vector, MAX_PEAK_HEIGHT, MAX_PEAK_WIDTH);
		// Local maxima validation (if found)
		LocalMaximaValidation(
			RIGHT_LINE,
			local_maxima_found,
			lane_centers,
			current_row,
			right_line_points,
			right_index,
			right_line_point_found);

		/* Left side scanning */ 
		left_line_point_found = false;
		// Prepare image row vector to scan
		image_row_vector = 
			(std::vector<int>) image.row(current_row).colRange(0, left_index);
		// Search for local maxima
		local_maxima_found = 
			LocMax_pw(image_row_vector, MAX_PEAK_HEIGHT, MAX_PEAK_WIDTH);
		// Local maxima validation (if found)
		LocalMaximaValidation(
			LEFT_LINE,
			local_maxima_found,
			lane_centers,
			current_row,
			left_line_points,
			left_index,
			left_line_point_found);

		// Center points calculation
		if (right_line_point_found == true)
		{	
			int cent = right_line_points.back().x - (LANE_WIDTH/2) > SAFE_MARGIN ? 
				right_line_points.back()
.x - (LANE_WIDTH/2) :
				SAFE_MARGIN;
            lane_centers.push_back(cv::Point2f(cent, current_row));
		 	last_center_position = lane_centers[2].x;
	 	}
		else if (left_line_point_found == true)
		{
			int cent = left_line_points.back().x + (LANE_WIDTH/2) < image_width - SAFE_MARGIN ? 
				left_line_points.back().x + (LANE_WIDTH/2):
				image_width - SAFE_MARGIN;
            lane_centers.push_back(cv::Point2f(cent, current_row));
			last_center_position = lane_centers[2].x;    
         }
         else
            last_center_position = 
                DRIVE_RIGHT_LANE == true? 
                RIGHT_LANE_ORIGIN :
                LEFT_LANE_ORIGIN;

		current_row -= ROW_STEP;	
    }
    
    if(DEBUG)
	{
		// Draw lines begin
		cv::circle(
            image, cv::Point(left_line_points.front()), 
            3, 55, -1);
		cv::circle(
            image, cv::Point(right_line_points.front()), 
            3, 255, -1);
	
		// Draw lane centers
		for (std::vector<cv::Point>::iterator point = 
			lane_centers.begin() ; 
			point != lane_centers.end(); ++point)
			cv::circle(image, *point, 1, 155, -1);

		// Draw right line points
		for (std::vector<cv::Point>::iterator point = 
			right_line_points.begin() ; 
			point != right_line_points.end(); ++point)
			cv::circle(image, *point, 1, 250, -1);

		// Draw left line points
		for (std::vector<cv::Point>::iterator point = 
			left_line_points.begin() ; 
			point != left_line_points.end(); ++point)
			cv::circle(image, *point, 1, 50, -1);
	}
}

// Wrap perspective points
int a = 48, b = 48, c = 44, d = 44;
float scale_x = 0.4, scale_y = 1.2;
int startX=0,startY=90,width=640,height=350;

int main( int argc, char** argv )
{
	Mat img, image, img_cropped, img_scaled, img_scaled_gray, img_lambda,img_lambda3, img_lambda2, img_warped, img_warped3;
	String windowRGB = "Original RGB", windowCropped = "Cropped RGB", 
		windowScaled = "Scaled Image", windowScaledGray = "Gray Scaled Image",
		windowLambda = "Lambda Image", windowWarped = "Warped Image";
	
	img = imread("/home/rodrigo/catkin_ws/src/line_detection_mio/TestPictures/Luz2RGB_dobleCarril.jpg");
	if(! img.data)
	{
		cout<<"Sorry couldnt find the image"<<endl;
		return -1;
	}
															

	// Region of interest
	Mat ROI(img, Rect(startX,startY,width,height));
	ROI.copyTo(img_cropped);

	namedWindow(windowCropped);
	imshow(windowCropped, img_cropped);


	// Image Resizing
	resize(img_cropped, img_scaled, Size(), scale_x, scale_y, CV_INTER_LINEAR);

	// To gray scale color transform
	cvtColor(img_scaled, img_scaled_gray, CV_BGR2GRAY);

	// Points used for homology
	cv::Point2f image_points[4], object_points[4];

	// Get image size
	int image_width = img_scaled_gray.size().width;
	int image_height = img_scaled_gray.size().height;

    object_points[0].x = 0; 
    object_points[0].y = 280;
    object_points[1].x = image_width;
    object_points[1].y = 280;
    object_points[2].x = 0;
    object_points[2].y = image_height;
    object_points[3].x = image_width;
    object_points[3].y = image_height;

    image_points[0].x = 0;
    image_points[0].y = 0;
    image_points[1].x = image_width;
    image_points[1].y = 0; 
    image_points[2].x = image_width/2 - 43;	//////////////
    image_points[2].y = image_height;
    image_points[3].x = image_width/2 + 43;	//////////////
    image_points[3].y = image_height;

    img_lambda3 = cv::getPerspectiveTransform(object_points, image_points);
    cv::warpPerspective(img_scaled_gray, img_warped,
    					img_lambda3, img_scaled_gray.size());
	namedWindow("warped3");
	imshow("warped3", img_warped);


	cout << "Original Width : " << img.size().width << endl;			//Ancho de la imagen original
	cout << "Original Height: " << img.size().height << endl;		//Largo de la imagen original
	
	//namedWindow(windowCropped);
	//imshow(windowCropped, img_cropped);

	namedWindow(windowScaled);
	imshow(windowScaled, img_scaled_gray);

	//namedWindow(windowWarped);
	//imshow(windowWarped, img_warped);

	cout << "Cropped Width : " << img_scaled.size().width << endl;		//Ancho de la imagen cortada
	cout << "Cropped Height: " << img_scaled.size().height << endl;		//Largo de la imagen cortada

	cout << "Scaled Gray Width : " << image_width << endl;		//Ancho de la imagen cortada
	cout << "Scaled Gray Height: " << image_height << endl;		//Largo de la imagen cortada

	//////////////////////////////////////////////////////////////////////////
	std::vector<cv::Point> lane_centers;
	std::vector<cv::Point> left_line_points;
	std::vector<cv::Point> right_line_points;
	bool line_found;
	bool right_line_found;
	bool left_line_found;
	cv::Vec4f line;	

	// Image allocator and shape extraction
	image = img_warped;
	image_height = image.size().height;
	image_width = image.size().width;

	// Color transform used to fill black corners 
	float IMAGE_PERCENTAGE = 0.66;
	int GRAY_THRESHOLD = 30, FILTER_KERNEL_SIZE = 3;

	//namedWindow(windowCropped);
	//imshow(windowCropped, image);

	medianBlur(image, image, FILTER_KERNEL_SIZE); //Blurs an image using the median filter.

	LineDetection(image, image_height, image_width, lane_centers,
					 right_line_points, left_line_points);

	windowCropped = "LINE DETECTION";
	namedWindow(windowCropped);
	imshow(windowCropped, image);

	// Curvature degree calculation
	line_found = false;
	right_line_found = false;
	left_line_found = false;
	if (right_line_points.size() > MIN_RIGHT_LINE_POINTS)
	{
	     cv::fitLine(
			 right_line_points, line,
			 CV_DIST_L2, 0, 0.01 ,0.01);
	     line_found = true;    
	     right_line_found = true;    
	}		
	else if (left_line_points.size() > MIN_LEFT_LINE_POINTS)
	{
	     cv::fitLine(
			 left_line_points, line,
			 CV_DIST_L2, 0, 0.01, 0.01);
	     line_found = true; 
	     left_line_found = true;
	}		

	if (line_found == true)
	{
	    center_deviation = int(image_width/2) - lane_centers[1].x;	
		int p1 = line[2];
		int p2 = line[3];
	    int p3 = (line[2]+1)+100*line[0];
		int p4 = (line[3]+1)+100*line[1];
		
	    if (left_line_found == true)
	    {
			p3=left_line_points.back().x;
		 	p4=left_line_points.back().y; 
	    }
	    else if (right_line_found == true)
	    {
			p3=right_line_points.back().x;
			p4=right_line_points.back().y; 
	    }

	    float m1 = p4 - p2;
	    float m2 = p3 - p1;
	    float m = (m2 / m1); 
		 
		curvature_degree = SERVO_CENTER + int(atan(m)*(180.0/M_PI));
		cout << "curvature_degree: " << curvature_degree << endl;
		cout << "center_deviation: " << center_deviation << endl;	

	}

	waitKey(0);
	destroyAllWindows();

	return 0;
}