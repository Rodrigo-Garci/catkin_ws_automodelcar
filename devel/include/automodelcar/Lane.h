// Generated by gencpp from file automodelcar/Lane.msg
// DO NOT EDIT!


#ifndef AUTOMODELCAR_MESSAGE_LANE_H
#define AUTOMODELCAR_MESSAGE_LANE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace automodelcar
{
template <class ContainerAllocator>
struct Lane_
{
  typedef Lane_<ContainerAllocator> Type;

  Lane_()
    : header()
    , steering_value(0)
    , speed_value(0)
    , lane_angle(0)
    , error(0)  {
    }
  Lane_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , steering_value(0)
    , speed_value(0)
    , lane_angle(0)
    , error(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int16_t _steering_value_type;
  _steering_value_type steering_value;

   typedef int16_t _speed_value_type;
  _speed_value_type speed_value;

   typedef int16_t _lane_angle_type;
  _lane_angle_type lane_angle;

   typedef int16_t _error_type;
  _error_type error;





  typedef boost::shared_ptr< ::automodelcar::Lane_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::automodelcar::Lane_<ContainerAllocator> const> ConstPtr;

}; // struct Lane_

typedef ::automodelcar::Lane_<std::allocator<void> > Lane;

typedef boost::shared_ptr< ::automodelcar::Lane > LanePtr;
typedef boost::shared_ptr< ::automodelcar::Lane const> LaneConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::automodelcar::Lane_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::automodelcar::Lane_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace automodelcar

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'automodelcar': ['/home/rodrigo/catkin_ws_automodelcar/src/automodelcar/msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::automodelcar::Lane_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::automodelcar::Lane_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::automodelcar::Lane_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::automodelcar::Lane_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::automodelcar::Lane_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::automodelcar::Lane_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::automodelcar::Lane_<ContainerAllocator> >
{
  static const char* value()
  {
    return "449dd1ba0aa3590031ea448bf8dee0f9";
  }

  static const char* value(const ::automodelcar::Lane_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x449dd1ba0aa35900ULL;
  static const uint64_t static_value2 = 0x31ea448bf8dee0f9ULL;
};

template<class ContainerAllocator>
struct DataType< ::automodelcar::Lane_<ContainerAllocator> >
{
  static const char* value()
  {
    return "automodelcar/Lane";
  }

  static const char* value(const ::automodelcar::Lane_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::automodelcar::Lane_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"int16 steering_value\n"
"int16 speed_value\n"
"int16 lane_angle\n"
"int16 error\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::automodelcar::Lane_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::automodelcar::Lane_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.steering_value);
      stream.next(m.speed_value);
      stream.next(m.lane_angle);
      stream.next(m.error);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Lane_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::automodelcar::Lane_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::automodelcar::Lane_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "steering_value: ";
    Printer<int16_t>::stream(s, indent + "  ", v.steering_value);
    s << indent << "speed_value: ";
    Printer<int16_t>::stream(s, indent + "  ", v.speed_value);
    s << indent << "lane_angle: ";
    Printer<int16_t>::stream(s, indent + "  ", v.lane_angle);
    s << indent << "error: ";
    Printer<int16_t>::stream(s, indent + "  ", v.error);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AUTOMODELCAR_MESSAGE_LANE_H