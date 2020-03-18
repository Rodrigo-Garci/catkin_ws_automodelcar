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
      this.lane_angle = null;
      this.center_deviation = null;
      this.last_center_deviation = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('lane_angle')) {
        this.lane_angle = initObj.lane_angle
      }
      else {
        this.lane_angle = 0;
      }
      if (initObj.hasOwnProperty('center_deviation')) {
        this.center_deviation = initObj.center_deviation
      }
      else {
        this.center_deviation = 0;
      }
      if (initObj.hasOwnProperty('last_center_deviation')) {
        this.last_center_deviation = initObj.last_center_deviation
      }
      else {
        this.last_center_deviation = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Lane
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [lane_angle]
    bufferOffset = _serializer.int16(obj.lane_angle, buffer, bufferOffset);
    // Serialize message field [center_deviation]
    bufferOffset = _serializer.int16(obj.center_deviation, buffer, bufferOffset);
    // Serialize message field [last_center_deviation]
    bufferOffset = _serializer.int16(obj.last_center_deviation, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Lane
    let len;
    let data = new Lane(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [lane_angle]
    data.lane_angle = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [center_deviation]
    data.center_deviation = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [last_center_deviation]
    data.last_center_deviation = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 6;
  }

  static datatype() {
    // Returns string type for a message object
    return 'automodelcar/Lane';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '591f44b2768aa4fda6dac105bab22307';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
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

    if (msg.lane_angle !== undefined) {
      resolved.lane_angle = msg.lane_angle;
    }
    else {
      resolved.lane_angle = 0
    }

    if (msg.center_deviation !== undefined) {
      resolved.center_deviation = msg.center_deviation;
    }
    else {
      resolved.center_deviation = 0
    }

    if (msg.last_center_deviation !== undefined) {
      resolved.last_center_deviation = msg.last_center_deviation;
    }
    else {
      resolved.last_center_deviation = 0
    }

    return resolved;
    }
};

module.exports = Lane;
