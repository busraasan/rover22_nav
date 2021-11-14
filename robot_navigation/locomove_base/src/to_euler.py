#!/usr/bin/env python

import rospy
from sensor_msgs.msg import Imu
from tf.transformations import euler_from_quaternion

def callback(data):
	euler = (euler_from_quaternion([data.orientation.x,data.orientation.y,data.orientation.z,data.orientation.w]))
	print(euler[2])

if __name__ == "__main__":
	rospy.init_node("qua")
	sub = rospy.Subscriber("/imu/data", Imu, callback)
	rospy.spin()
	
	
