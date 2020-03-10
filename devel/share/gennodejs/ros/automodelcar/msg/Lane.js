// Auto-generated. Do not edit!

// (in-package automodelcar.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Lane {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.steering_value = null;
      this.speed_value = null;
      this.lane_angle = null;
      this.error = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('steering_value')) {
        this.steering_value = initObj.steering_value
      }
      else {
        this.steering_value = 0;
      }
      if (initObj.hasOwnProperty('speed_value')) {
        this.speed_value = initObj.speed_value
      }
      else {
        this.speed_value = 0;
      }
      if (initObj.hasOwnProperty('lane_angle')) {
        this.lane_angle = initObj.lane_angle
      }
      else {
        this.lane_angle = 0;
      }
      if (initObj.hasOwnProperty('error')) {
        this.error = initObj.error
      }
      else {
        this.error = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Lane
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [steering_value]
    bufferOffset = _serializer.int16(obj.steering_value, buffer, bufferOffset);
    // Serialize message field [speed_value]
    bufferOffset = _serializer.int16(obj.speed_value, buffer, bufferOffset);
    // Serialize message field [lane_angle]
    bufferOffset = _serializer.int16(obj.lane_angle, buffer, bufferOffset);
    // Serialize message field [error]
    bufferOffset = _serializer.int16(obj.error, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Lane
    let len;
    let data = new Lane(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [steering_value]
    data.steering_value = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [speed_value]
    data.speed_value = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [lane_angle]
    data.lane_angle = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [error]
    data.error = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'automodelcar/Lane';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '449dd1ba0aa3590031ea448bf8dee0f9';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Lane(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.steering_value !== undefined) {
      resolved.steering_value = msg.steering_value;
    }
    else {
      resolved.steering_value = 0
    }

    if (msg.speed_value !== undefined) {
      resolved.speed_value = msg.speed_value;
    }
    else {
      resolved.speed_value = 0
    }

    if (msg.lane_angle !== undefined) {
      resolved.lane_angle = msg.lane_angle;
    }
    else {
      resolved.lane_angle = 0
    }

    if (msg.error !== undefined) {
      resolved.error = msg.error;
    }
    else {
      resolved.error = 0
    }

    return resolved;
    }
};

module.exports = Lane;
