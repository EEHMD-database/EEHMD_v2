#include "ros/ros.h"
#include "std_msgs/String.h"
#include "leapmsg.h"
#include "JointsCoordinates.h"
#include "hand_estimation.h"


Hand_model::Hand_estimation hand;
ros_eehmd::JointsCoordinates joints_coordinates;

ros::Publisher joints_coordinate_publisher;

void chatterCallback(const ros_eehmd::leapmsgConstPtr& leap_msg )
{
  if (leap_msg->hands_count > 0){

  hand.compute_model_from_leap_msg(*leap_msg);
  ros_eehmd::JointsCoordinates joints_coordinates_temp;
  joints_coordinates_temp.data.insert(joints_coordinates_temp.data.begin(), hand.joints_coordinates, hand.joints_coordinates + 18);
  joints_coordinates_temp.header = leap_msg->header;
  joints_coordinates=joints_coordinates_temp;

  joints_coordinate_publisher.publish(joints_coordinates);
  }
}

int main(int argc, char **argv)
{
 ros::init(argc, argv, "manifold");

 ros::NodeHandle n;

 ros::Subscriber subleap = n.subscribe("leapmotion_raw", 1000, chatterCallback);
joints_coordinate_publisher = n.advertise<ros_eehmd::JointsCoordinates>("joints_coordinates_from_leap", 1000);

 ros::Rate loop_rate(100);

 while (ros::ok()){



	 ros::spinOnce();
	 loop_rate.sleep();
 }	
  return 0;
}   
