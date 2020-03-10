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
  :slots (_header _steering_value _speed_value _lane_angle _error ))

(defmethod automodelcar::Lane
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:steering_value __steering_value) 0)
    ((:speed_value __speed_value) 0)
    ((:lane_angle __lane_angle) 0)
    ((:error __error) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _steering_value (round __steering_value))
   (setq _speed_value (round __speed_value))
   (setq _lane_angle (round __lane_angle))
   (setq _error (round __error))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:steering_value
   (&optional __steering_value)
   (if __steering_value (setq _steering_value __steering_value)) _steering_value)
  (:speed_value
   (&optional __speed_value)
   (if __speed_value (setq _speed_value __speed_value)) _speed_value)
  (:lane_angle
   (&optional __lane_angle)
   (if __lane_angle (setq _lane_angle __lane_angle)) _lane_angle)
  (:error
   (&optional __error)
   (if __error (setq _error __error)) _error)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int16 _steering_value
    2
    ;; int16 _speed_value
    2
    ;; int16 _lane_angle
    2
    ;; int16 _error
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int16 _steering_value
       (write-word _steering_value s)
     ;; int16 _speed_value
       (write-word _speed_value s)
     ;; int16 _lane_angle
       (write-word _lane_angle s)
     ;; int16 _error
       (write-word _error s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int16 _steering_value
     (setq _steering_value (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _speed_value
     (setq _speed_value (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _lane_angle
     (setq _lane_angle (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _error
     (setq _error (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get automodelcar::Lane :md5sum-) "449dd1ba0aa3590031ea448bf8dee0f9")
(setf (get automodelcar::Lane :datatype-) "automodelcar/Lane")
(setf (get automodelcar::Lane :definition-)
      "Header header
int16 steering_value
int16 speed_value
int16 lane_angle
int16 error

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



(provide :automodelcar/Lane "449dd1ba0aa3590031ea448bf8dee0f9")


