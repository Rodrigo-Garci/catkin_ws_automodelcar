; Auto-generated. Do not edit!


(cl:in-package automodelcar-msg)


;//! \htmlinclude Intersection.msg.html

(cl:defclass <Intersection> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (distance
    :reader distance
    :initarg :distance
    :type cl:fixnum
    :initform 0)
   (angle
    :reader angle
    :initarg :angle
    :type cl:float
    :initform 0.0))
)

(cl:defclass Intersection (<Intersection>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Intersection>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Intersection)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name automodelcar-msg:<Intersection> is deprecated: use automodelcar-msg:Intersection instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Intersection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader automodelcar-msg:header-val is deprecated.  Use automodelcar-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <Intersection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader automodelcar-msg:distance-val is deprecated.  Use automodelcar-msg:distance instead.")
  (distance m))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <Intersection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader automodelcar-msg:angle-val is deprecated.  Use automodelcar-msg:angle instead.")
  (angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Intersection>) ostream)
  "Serializes a message object of type '<Intersection>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'distance)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Intersection>) istream)
  "Deserializes a message object of type '<Intersection>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'distance) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Intersection>)))
  "Returns string type for a message object of type '<Intersection>"
  "automodelcar/Intersection")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Intersection)))
  "Returns string type for a message object of type 'Intersection"
  "automodelcar/Intersection")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Intersection>)))
  "Returns md5sum for a message object of type '<Intersection>"
  "8684906e20e1765a2ab9c77ed3f64e29")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Intersection)))
  "Returns md5sum for a message object of type 'Intersection"
  "8684906e20e1765a2ab9c77ed3f64e29")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Intersection>)))
  "Returns full string definition for message of type '<Intersection>"
  (cl:format cl:nil "Header header~%int8 distance~%float32 angle~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Intersection)))
  "Returns full string definition for message of type 'Intersection"
  (cl:format cl:nil "Header header~%int8 distance~%float32 angle~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Intersection>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Intersection>))
  "Converts a ROS message object to a list"
  (cl:list 'Intersection
    (cl:cons ':header (header msg))
    (cl:cons ':distance (distance msg))
    (cl:cons ':angle (angle msg))
))
