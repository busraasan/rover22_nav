#!/usr/bin/python

import rospy
import actionlib
import argparse

from locomotor_msgs.msg import NavigateToPoseAction, NavigateToPoseGoal

def print_feedback(feedback):
    pose = feedback.state.global_pose.pose
    vel = feedback.state.current_velocity.velocity
    print('%.2f %.2f %.2f | %.2f %.2f' % (pose.x, pose.y, pose.theta,
                                          vel.x, vel.theta))
    print('Global plan: %d poses' % len(feedback.state.global_plan.poses))
    print('%.2f %.2f %.2f' % (feedback.percent_complete,
                              feedback.distance_traveled,
                              feedback.estimated_distance_remaining))


parser = argparse.ArgumentParser()
parser.add_argument('x', nargs='?', type=float, default=0.0)
parser.add_argument('y', nargs='?', type=float, default=0.0)
parser.add_argument('theta', nargs='?', type=float, default=0.0)
parser.add_argument('-f', '--frame_id', default='map')
parser.add_argument('-n', '--namespace', default='/locomotor')
args = parser.parse_args()

rospy.init_node('send_action', anonymous=True)
client = actionlib.SimpleActionClient(args.namespace + '/navigate', NavigateToPoseAction)
client.wait_for_server()
goal = NavigateToPoseGoal()
goal.goal.pose.x = -1.0
goal.goal.pose.y = 0.0
goal.goal.pose.theta = 0.0
goal.goal.header.frame_id = "map"
client.send_goal(goal, feedback_cb = print_feedback)
client.wait_for_result()
print(client.get_result())
