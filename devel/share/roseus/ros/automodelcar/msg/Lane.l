;; Auto-generated. Do not edit!


(when (boundp 'automodelcar::Lane)
  (if (not (find-package "AUTOMODELCAR"))
    (make-package "AUTOMODELCAR"))
  (shadow 'Lane (find-package "AUTOMODELCAR")))
(unless (find-package "AUTOMODELCAR::LANE")
  (make-package "AUTOMODELCAR::LANE"))

(in-package "ROS")
;;//! \htmlinclude Lane.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass automodelcar::Lane
  :super ros::object
  :slots (_header _lane_angle _center_deviation _last_center_deviation ))

(defmethod automodelcar::Lane
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:lane_angle __lane_angle) 0)
    ((:center_deviation __center_deviation) 0)
    ((:last_center_deviation __last_center_deviation) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _lane_angle (round __lane_angle))
   (setq _center_deviation (round __center_deviation))
   (setq _last_center_deviation (round __last_center_deviation))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:lane_angle
   (&optional __lane_angle)
   (if __lane_angle (setq _lane_angle __lane_angle)) _lane_angle)
  (:center_deviation
   (&optional __center_deviation)
   (if __center_deviation (setq _center_deviation __center_deviation)) _center_deviation)
  (:last_center_deviation
   (&optional __last_center_deviation)
   (if __last_center_deviation (setq _last_center_deviation __last_center_deviation)) _last_center_deviation)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int16 _lane_angle
    2
    ;; int16 _center_deviation
    2
    ;; int16 _last_center_deviation
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int16 _lane_angle
       (write-word _lane_angle s)
     ;; int16 _center_deviation
       (write-word _center_deviation s)
     ;; int16 _last_center_deviation
       (write-word _last_center_deviation s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int16 _lane_angle
     (setq _lane_angle (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _center_deviation
     (setq _center_deviation (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _last_center_deviation
     (setq _last_center_deviation (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get automodelcar::Lane :md5sum-) "591f44b2768aa4fda6dac105bab22307")
(setf (get automodelcar::Lane :datatype-) "automodelcar/Lane")
(setf (get automodelcar::Lane :definition-)
      "Header header
int16 lane_angle
int16 center_deviation
int16 last_center_deviation

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



(provide :automodelcar/Lane "591f44b2768aa4fda6dac105bab22307")


