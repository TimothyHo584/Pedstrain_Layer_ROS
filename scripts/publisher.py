#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import Float32

data = 0.0
def talker():
    global data
    pub = rospy.Publisher('pedestrain/pedestrain_point', Float32, queue_size=10)
    rospy.init_node('pedestrain', anonymous=True)
    rate = rospy.Rate(1) # 1hz
    while not rospy.is_shutdown():
        rospy.loginfo(data)
        pub.publish(data)
        data += 0.1
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
