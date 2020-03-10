;; Auto-generated. Do not edit!


(when (boundp 'automodelcar::Intersection)
  (if (not (find-package "AUTOMODELCAR"))
    (make-package "AUTOMODELCAR"))
  (shadow 'Intersection (find-package "AUTOMODELCAR")))
(unless (find-package "AUTOMODELCAR::INTERSECTION")
  (make-package "AUTOMODELCAR::INTERSECTION"))

(in-package "ROS")
;;//! \htmlinclude Intersection.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass automodelcar::Intersection
  :super ros::object
  :slots (_header _distance _angle ))

(defmethod automodelcar::Intersection
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:distance __distance) 0)
    ((:angle __angle) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _distance (round __distance))
   (setq _angle (float __angle))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int8 _distance
    1
    ;; float32 _angle
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int8 _distance
       (write-byte _distance s)
     ;; float32 _angle
       (sys::poke _angle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int8 _distance
     (setq _distance (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _distance 127) (setq _distance (- _distance 256)))
   ;; float32 _angle
     (setq _angle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get automodelcar::Intersection :md5sum-) "8684906e20e1765a2ab9c77ed3f64e29")
(setf (get automodelcar::Intersection :datatype-) "automodelcar/Intersection")
(setf (get automodelcar::Intersection :definition-)
      "Header header
int8 distance
float32 angle

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :automodelcar/Intersection "8684906e20e1765a2ab9c77ed3f64e29")


