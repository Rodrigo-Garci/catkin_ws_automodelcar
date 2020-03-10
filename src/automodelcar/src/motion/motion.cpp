#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include "sensor_msgs/Joy.h"

int transform(float value, float JoyMin, float JoyMax, float TargetMin, float TargetMax)
{
  float joyRange;
  float targetRange;
  float valueScaled;
  float valueS;

  //Figure out how 'wide' each range is
  joyRange = JoyMax - JoyMin;
  targetRange = TargetMax - TargetMin;

  //Convert the left range into a 0-1 range (float)
  valueScaled = float(value - JoyMin) / float(joyRange);

  //Convert the 0-1 range into a value in the right range.
  valueS = TargetMin + (valueScaled * targetRange);
  return int(valueS);
}

class auto_control
{
  private:
    ros::NodeHandle nh_;
    ros::NodeHandle priv_nh_;
    ros::Subscriber sub_joy_;
    ros::Publisher pub_speed_;
    ros::Publisher pub_steering_;


    int maximum_rpm_;
    int minimum_rpm_;
    int maximum_steering_;
    int minimum_steering_;

  public:
    auto_control(ros::NodeHandle nh) : nh_(nh), priv_nh_("~")
    {
      priv_nh_.param<int>("maximum_rpm", maximum_rpm_, -1000);
      priv_nh_.param<int>("minimum_rpm", minimum_rpm_, 1000);
      priv_nh_.param<int>("maximum_rpm", maximum_rpm_, 180);
      priv_nh_.param<int>("minimum_rpm", minimum_rpm_, 0);
      sub_joy_ = nh.subscribe("/joy", 1, &auto_control::movementCallBack,this);
      pub_steering_ = nh.advertise<std_msgs::Int16>(nh.resolveName("/manual_control/steering"), 1);
      pub_speed_ = nh.advertise<std_msgs::Int16>(nh.resolveName("/manual_control/speed"), 1);
      ROS_INFO("####################################################");
      ROS_INFO("CAR MANUAL CONTROLLER PS3");
      ROS_INFO("\t/manual_control/speed");
      ROS_INFO("\t/manual_control/steering");
      ROS_ERROR("INICIALIZED, MOVE THE JOYSTICKS");
      ROS_INFO("####################################################");
    }
    ~auto_control(){}
    void movementCallBack(const sensor_msgs::Joy movement);
};

void auto_control::movementCallBack(const sensor_msgs::Joy movement)
{
  std_msgs::Int16 DesiredSpeed;
  std_msgs::Int16 DesiredSteering;
  float LeftJoy;
  float RightJoy;

  LeftJoy = movement.axes[1];
  RightJoy = movement.axes[3];
  DesiredSpeed.data = transform(LeftJoy, -1, 1, minimum_rpm_, maximum_rpm_);
  DesiredSteering.data = transform(RightJoy, -1, 1, minimum_steering_, maximum_steering_);

  ROS_ERROR_STREAM("Control: received speed: "<<DesiredSpeed);
  ROS_ERROR_STREAM("Control: received steering: "<<DesiredSteering);

  pub_speed_.publish(DesiredSpeed);
  pub_steering_.publish(DesiredSteering);
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "auto_control_node");
  ros::NodeHandle nh;
  auto_control control1(nh);
  while(ros::ok())
  {
    ros::spinOnce();
  }
  return 0;
}
