#include "/home/basan/dummy_ws/src/robot_navigation/custom_recovery/include/custom_recovery.h"
#include <pluginlib/class_list_macros.h>
#include <ros/ros.h>
#include <iostream>
#include <tf2/utils.h>
#include "/opt/ros/melodic/include/base_local_planner/costmap_model.h"


PLUGINLIB_EXPORT_CLASS(custom_recovery::CustomRecovery, nav_core::RecoveryBehavior)


namespace custom_recovery
{
    CustomRecovery::CustomRecovery(): tfListener_(NULL), globalCostmapROS_(NULL), localCostmapROS_(NULL), worldModel_(NULL), initialized_(false)
    {
    }

    CustomRecovery::~CustomRecovery()
    {
        std::cout << "Custom Recovery Destructorr!!" << std::endl;
    }

    void CustomRecovery::initialize(std::string name, tf2_ros::Buffer* tfListener,
        costmap_2d::Costmap2DROS* globalCostmapROS,
        costmap_2d::Costmap2DROS* localCostmapROS){

        if(!initialized_){
            name_ = name;
            tfListener_ = tfListener;
            globalCostmapROS_ = globalCostmapROS;
            localCostmapROS_ = localCostmapROS;
            worldModel_ = new base_local_planner::CostmapModel(
            *localCostmapROS_->getCostmap());

            // set initialization state
            initialized_ = true;
            std::cout << "initialized" << std::endl;
        } else {
            std::cout << "already initialized" << std::endl;
        }
        
    }

    void CustomRecovery::runBehavior(){

        if (!initialized_)
        {
            ROS_ERROR("This object must be initialized before runBehavior is called");
            return;
        }

        ROS_WARN("Lann recovery behavior started.");
        ros::Rate r(10);
        ros::NodeHandle n;
        r.sleep();

    }

}

int main(){
    return 0;
}
