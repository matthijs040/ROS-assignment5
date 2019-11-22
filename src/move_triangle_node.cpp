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

// A global copy of the newest triangle is nescesary if you want to test its value in main()
// assignment5::Triangle triangle = assignment5::Triangle();


    ros::Publisher goalPub;

// Callback to respond to the triangle message sent on the cmd topic.
void cmdCallback(const assignment5::TriangleConstPtr&  msg )
{
    auto goal = turtlebot3_example::Turtlebot3ActionGoal();
    goal.goal.goal.x = msg->sideLength;
    goalPub.publish(goal);
}


const turtlebot3_example::Turtlebot3ActionGoal cmdHandler( const assignment5::TriangleConstPtr& msg )
{
    turtlebot3_example::Turtlebot3ActionGoal action = turtlebot3_example::Turtlebot3ActionGoal();
    action.goal.goal.x = msg->sideLength;

    auto result = turtlebot3_example::Turtlebot3ActionGoal(action);
    return result;
}



int main(int argc, char *argv[])
{
    ros::init(argc, argv, "move_triangle_node");
    ros::NodeHandle n = ros::NodeHandle();

    ros::Subscriber cmdSub = n.subscribe("/cmd", 1, cmdCallback );
    
    SubscriptionPublisher<const turtlebot3_example::Turtlebot3ActionGoal, const assignment5::TriangleConstPtr&> 
    sp = SubscriptionPublisher("/turtlebot3/goal", "/cmd", std::function(cmdHandler) );

    ros::spin();
    
    return 0;
}
