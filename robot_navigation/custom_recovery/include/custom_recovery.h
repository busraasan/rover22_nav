#ifndef CUSTOM_RECOVERY_H
#define CUSTOM_RECOVERY_H

#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <costmap_2d/costmap_2d_ros.h>
#include <nav_core/recovery_behavior.h>
#include "/opt/ros/melodic/include/base_local_planner/costmap_model.h"
#include <geometry_msgs/Twist.h>
#include <tf2/utils.h>


namespace custom_recovery
{

  /**
   * @class CustomRecovery
   * @brief A locomove_base plugin that tries to print something...
   */
  class CustomRecovery : public nav_core::RecoveryBehavior
  {
    private:
      //! name of instance
      std::string name_;
      //! contains the initialization state of the plugin
      bool initialized_;
      tf2_ros::Buffer* tfListener_;
      //! local costmap ros wrapper ptr
      costmap_2d::Costmap2DROS* localCostmapROS_;
      //! global costmap ros wrapper ptr
      costmap_2d::Costmap2DROS* globalCostmapROS_;
      //! costmap world model
      base_local_planner::CostmapModel* worldModel_;

    public:

      /**
       * @brief Constructor
       */
      CustomRecovery();

      /**
       * @brief Destructor
       */
      ~CustomRecovery();

      /**
       * @brief Initializes plugin
       * @param name: name of instance
       * @param tfListener: ptr to the tf transform listener of the node
       * @param globalCostmapROS: ptr to the global costmap of the node
       * @param localCostmapROS: ptr to the local costmap of the node
       */
      void initialize(std::string name, tf2_ros::Buffer* tfListener,
        costmap_2d::Costmap2DROS* globalCostmapROS,
        costmap_2d::Costmap2DROS* localCostmapROS);

      /**
       * @brief Executes the car maneuver recovery behavior
       */
      void runBehavior();

      /**
       * @brief Calculates line cost
       * @param point1: line start point
       * @param point2: line end point
       */

  };

}  // namespace custom_recovery

#endif