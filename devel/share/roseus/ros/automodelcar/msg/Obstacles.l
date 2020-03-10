;; Auto-generated. Do not edit!


(when (boundp 'automodelcar::Obstacles)
  (if (not (find-package "AUTOMODELCAR"))
    (make-package "AUTOMODELCAR"))
  (shadow 'Obstacles (find-package "AUTOMODELCAR")))
(unless (find-package "AUTOMODELCAR::OBSTACLES")
  (make-package "AUTOMODELCAR::OBSTACLES"))

(in-package "ROS")
;;//! \htmlinclude Obstacles.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass automodelcar::Obstacles
  :super ros::object
  :slots (_header _detected_obstacles _obstacle_vertices ))

(defmethod automodelcar::Obstacles
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:detected_obstacles __detected_obstacles) 0)
    ((:obstacle_vertices __obstacle_vertices) (let (r) (dotimes (i 0) (push (instance geometry_msgs::Point :init) r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _detected_obstacles (round __detected_obstacles))
   (setq _obstacle_vertices __obstacle_vertices)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:detected_obstacles
   (&optional __detected_obstacles)
   (if __detected_obstacles (setq _detected_obstacles __detected_obstacles)) _detected_obstacles)
  (:obstacle_vertices
   (&rest __obstacle_vertices)
   (if (keywordp (car __obstacle_vertices))
       (send* _obstacle_vertices __obstacle_vertices)
     (progn
       (if __obstacle_vertices (setq _obstacle_vertices (car __obstacle_vertices)))
       _obstacle_vertices)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int8 _detected_obstacles
    1
    ;; geometry_msgs/Point[] _obstacle_vertices
    (apply #'+ (send-all _obstacle_vertices :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int8 _detected_obstacles
       (write-byte _detected_obstacles s)
     ;; geometry_msgs/Point[] _obstacle_vertices
     (write-long (length _obstacle_vertices) s)
     (dolist (elem _obstacle_vertices)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int8 _detected_obstacles
     (setq _detected_obstacles (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _detected_obstacles 127) (setq _detected_obstacles (- _detected_obstacles 256)))
   ;; geometry_msgs/Point[] _obstacle_vertices
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _obstacle_vertices (let (r) (dotimes (i n) (push (instance geometry_msgs::Point :init) r)) r))
     (dolist (elem- _obstacle_vertices)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get automodelcar::Obstacles :md5sum-) "c8ba9cc95104a59374561b25f84c7880")
(setf (get automodelcar::Obstacles :datatype-) "automodelcar/Obstacles")
(setf (get automodelcar::Obstacles :definition-)
      "Header header
int8 detected_obstacles
geometry_msgs/Point[] obstacle_vertices


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

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :automodelcar/Obstacles "c8ba9cc95104a59374561b25f84c7880")


