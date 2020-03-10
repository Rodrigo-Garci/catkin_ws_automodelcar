#include "ros/ros.h"
#include <std_msgs/String.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Float32.h>
#include <automodelcar/Lane.h>
#include <geometry_msgs/Twist.h>
#include "automodelcar/Lane.h"
#include "lane_follower.h"

class lane_follower
{
	private:
	    ros::NodeHandle nh_;
	    ros::NodeHandle priv_nh_;
	    ros::Publisher pub_steering_;
	    ros::Publisher pub_speed_;
	    ros::Subscriber sub_angle_;
	    std_msgs::Int16 comm_steering_;
	    std_msgs::Int16 comm_speed_;

      int maximum_positive_rpm_, maximum_negative_rpm_;
      int maximum_steering_;
      int minimum_steering_;
      int angle_;
      float alfa_;
      float ki_, kp_, kd_;
      float yaw_, error_yaw_, sp_yaw_, ctrl_yaw_;
      float angle_e_, last_angle_, angle_int_, angle_new_;


    public:
    	lane_follower(ros::NodeHandle nh) : nh_(nh), priv_nh_("~")
    	{
      priv_nh_.param<int>("maximum_positive_rpm", maximum_positive_rpm_, -1000);
      priv_nh_.param<int>("minimum_negative_rpm", maximum_negative_rpm_, 1000);
      priv_nh_.param<int>("maximum_steering", maximum_steering_, 170);
      priv_nh_.param<int>("minimum_steering", minimum_steering_, 10);
      priv_nh_.param<float>("angle_int", angle_int_, 0);
      priv_nh_.param<float>("kp", kp_, 0.9);
      priv_nh_.param<float>("kd", kd_, 0.8);
      priv_nh_.param<float>("ki", ki_, 0.00);
      priv_nh_.param<float>("alfa", alfa_, 0.75);
		  pub_steering_ = nh.advertise<std_msgs::Int16>(nh.resolveName("/manual_control/steering"), 1);
		  pub_speed_ = nh.advertise<std_msgs::Int16>(nh.resolveName("/manual_control/speed"), 1);
		  sub_angle_ = nh.subscribe("/lane_detection", 1, &lane_follower::angle_Callback, this);    		
    	}
    	~lane_follower(){}
    	void angle_Callback(const automodelcar::Lane& lane);
};

void lane_follower::angle_Callback(const automodelcar::Lane& lane)
{
  ////////////////////////////CONTROL ON/OFF////////////////////////////
	/*angle_ = lane.lane_angle;
	
  if (angle_ >= 95)
  {
    comm_steering_.data = 170;
  }
  else if (angle_ <= 85)
  {
    comm_steering_.data = 10;
  }
  else
  {
    comm_steering_.data = 90;
  }
  //////////////////////////////////////////////////////////////////*/

  ////////////////////////////CONTROL PD////////////////////////////
  angle_e_ = angle_e_*alfa_+(1-alfa_)*(lane.lane_angle);
  error_yaw_ = (angle_e_);
  angle_int_ = angle_int_ + angle_e_;
  if((angle_int_*ki_)>5 || (angle_int_*ki_<-5)){
    angle_int_= 0;
  }

  if(angle_e_ == 0 || (angle_e_>0&&angle_e_<1) || (angle_e_<0&&angle_e_>-1)){
    ctrl_yaw_ = 0;
  }
  else{
    ctrl_yaw_ = 10 + ((kp_*angle_e_)+(ki_*angle_int_)+(kd_*(angle_e_-last_angle_)));
  }
  last_angle_ = angle_e_;

  if(ctrl_yaw_ < 10){
    ctrl_yaw_ = 10;
  }
  else if(ctrl_yaw_ > 170.0){
    ctrl_yaw_ = 170.0;
  } 
  //////////////////////////////////////////////////////////////////
  comm_steering_.data = (int)ctrl_yaw_;

  comm_speed_.data = SpeedSaturation(CalculateSpeedPWM(comm_steering_.data),
                                                    comm_speed_.data);

  pub_speed_.publish(comm_speed_);
  pub_steering_.publish(comm_steering_);

  ROS_INFO("Lane angle: %i", (int)lane.lane_angle);
  ROS_INFO("Speed: %irpm ", (int)comm_speed_.data);
  ROS_INFO("Steering Angle: %i\n", (int)comm_steering_.data);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "lane_follower");
  ros::NodeHandle nh;
  lane_follower lf(nh);
  ros::Rate(100); //100 Hz, cada 0.01 segundos
  while(ros::ok())
  {
    ros::spinOnce();
  }
  return 0;
}