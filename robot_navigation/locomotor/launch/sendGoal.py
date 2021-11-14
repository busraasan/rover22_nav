#!/usr/bin/env python
import rospy
import actionlib
from geometry_msgs.msg import PoseStamped
from locomotor_msgs.msg import NavigateToPoseAction, NavigateToPoseGoal
from tf.transformations import euler_from_quaternion

class goalSender():
	def __init__(self):

		self.goal = NavigateToPoseGoal()
		self.goal.goal.pose.x = 0.0
		self.goal.goal.pose.y = 0.0
		self.goal.goal.pose.theta = 0.0
		self.goal.goal.header.frame_id = "map"

		rospy.init_node('goalListener', anonymous=True)

		self.client = actionlib.SimpleActionClient('/locomotor/navigate', NavigateToPoseAction)
		self.pose_sub = rospy.Subscriber("/move_base_simple/goal", PoseStamped, self.poseCallback)

		self.client.wait_for_server()

		self.rate = rospy.Rate(10) #10Hz

		print('Give your goal using 2D nav goal!')

		rospy.spin()

	def poseCallback(self, new_goal):
		self.goal.goal.pose.x = new_goal.pose.position.x
		self.goal.goal.pose.y = new_goal.pose.position.y
		orientation = new_goal.pose.orientation
		self.goal.goal.pose.theta = euler_from_quaternion([orientation.x, orientation.y, orientation.z, orientation.w])[2]
		self.goal.goal.header.frame_id = new_goal.header.frame_id
		self.client.send_goal(self.goal)

if __name__ == '__main__':
    goalSender()
