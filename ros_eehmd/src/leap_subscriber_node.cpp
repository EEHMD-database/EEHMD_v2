#include "ros/ros.h"
#include "std_msgs/String.h"
#include "leapmsg.h"


void chatterCallback(const ros_eehmd::leapmsgConstPtr& leap_msg )
{
  ROS_INFO("I heard:thumb metacarpal= [%f]", leap_msg->thumb_metacarpal.x);
}

int main(int argc, char **argv)
{
 ros::init(argc, argv, "manifold");

 ros::NodeHandle n;

ros::Subscriber subleap = n.subscribe("leapmotion_raw", 1000, chatterCallback);

 ros::spin();

  return 0;
}   
