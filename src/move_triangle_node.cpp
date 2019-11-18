#include "ros/ros.h"
#include <string>
#include "../include/assignment5/Triangle.h"

assignment5::Triangle triangle = assignment5::Triangle();

void cmdCallback(const assignment5::TriangleConstPtr&  msg )
{
    triangle.cw         = msg->cw;
    triangle.sideLength = msg->sideLength;

    


}


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "move_triangle_node");
    ros::NodeHandle n = ros::NodeHandle();
    ros::Subscriber cmdSub = n.subscribe("/cmd", 1, cmdCallback );

    while(triangle.sideLength == assignment5::Triangle().sideLength )
    {
        ros::spinOnce();
    }

    std::cout << triangle.sideLength;


    
    return 0;
}
