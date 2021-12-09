#ifndef DWB_CRITICS_ROTATE_BEFORE_START_H
#define DWB_CRITICS_ROTATE_BEFORE_START_H

#include <dwb_local_planner/trajectory_critic.h>
#include <iostream>

namespace dwb_critics
{
/**
 * @class RotateBeforeStartCritic
 * @brief Robot point towards to the global plan before starting to move in linear motion.
 */
    class RotateBeforeStartCritic : public dwb_local_planner::TrajectoryCritic
    {
    public:
        void onInit() override;
        double scoreTrajectory(const dwb_msgs::Trajectory2D& traj) override;
        void reset();
        bool prepare(const geometry_msgs::Pose2D& pose, 
                     const nav_2d_msgs::Twist2D& vel,
                     const geometry_msgs::Pose2D& goal,
                     const nav_2d_msgs::Path2D& global_plan);
    protected:
        geometry_msgs::Pose2D current_pose_;
        geometry_msgs::Pose2D start_pose_;
        geometry_msgs::Pose2D start_pose_2;
        nav_2d_msgs::Path2D global_plan_;
        float start_yaw_;
        bool is_start_;
        double start_yaw_tolerance_;
        bool is_reached;
    };
}

#endif //DWB_CRITICS_ROTATE_BEFORE_START_H
