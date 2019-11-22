#include "ros/ros.h"
#include <string>

// Hard copy of the Triangle.h header with the generated code from the .msg file. 
// Copied from ../../devel/include/Triangle.h
// NOTE: Might want to replace it with a link or automatically synced file if possible.
#include "../include/assignment5/Triangle.h"

#include "../include/assignment5/subscriptionPublisher.h"

// Message headers defining the various turtlebot3-actionlib-server <-> client messages
#include "turtlebot3_example/Turtlebot3ActionGoal.h"
#include "turtlebot3_example/Turtlebot3ActionFeedback.h"
#include "turtlebot3_example/Turtlebot3ActionResult.h"

//#include "actionlib/server/"

#include "turtlebot3_example/Turtlebot3Goal.h"

const turtlebot3_example::Turtlebot3ActionGoal cmdHandler( const assignment5::TriangleConstPtr& msg )
{
    ROS_INFO("Received Triangle message.");

    turtlebot3_example::Turtlebot3ActionGoal action = turtlebot3_example::Turtlebot3ActionGoal();
    action.goal.goal.x = msg->sideLength;
    action.goal.goal.y = msg->sideLength;
    action.goal.goal.z = msg->sideLength;

    

    auto result = turtlebot3_example::Turtlebot3ActionGoal(action);
    return result;
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "move_triangle_node");
    ros::NodeHandle n = ros::NodeHandle();
    
    SubscriptionPublisher<const turtlebot3_example::Turtlebot3ActionGoal, const assignment5::TriangleConstPtr&> 
    sp = SubscriptionPublisher("/turtlebot3/goal", "/cmd", std::function(cmdHandler) );

    ROS_INFO("Awaiting a Triangle message on the /cmd topic.");

    ros::spin();
    
    return 0;
}
