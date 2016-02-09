//============================================================================
// Name        : costtest.cpp
// Author      : Gabriel Earley
// Version     : #1.0
// Copyright   : Your copyright notice
// Description :
//==============================================================================
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <stdlib.h>
#include <costmap_2d/costmap_2d_ros.h>
#include <tf/transform_listener.h>
#include <sstream>
#include <iostream>
using namespace std;

typedef costmap_2d::Costmap2DROS costmapROS;
typedef costmap_2d::Costmap2D costmap;

int main(int argc, char** argv) {
	ros::init(argc,argv,"costtest");
	//Used as a constructor and destructor of ROS nodes
	ros::NodeHandle costtest;
	char *p;
	int index_x, index_y;
	costmap test_map;
	if(argc == 1)
		{
		index_x = 0;
		index_y = 0;
		}
		else if(argc == 2){
		index_x = strtol(argv[1],&p,10);
		index_y = 0;
		}
		else if(argc == 3)
		{
		index_x = strtol(argv[1],&p,10);
		index_y = strtol(argv[2],&p,10);
		}
	tf::TransformListener tf(ros::Duration(10));
	costmapROS costmap("test_costmap", tf);
	test_map = *costmap.getCostmap();
	ROS_INFO("Value is %s", test_map.getCost(index_x,index_y));
return 0;
}
