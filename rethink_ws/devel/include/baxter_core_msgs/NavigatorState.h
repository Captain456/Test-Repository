// Generated by gencpp from file baxter_core_msgs/NavigatorState.msg
// DO NOT EDIT!


#ifndef BAXTER_CORE_MSGS_MESSAGE_NAVIGATORSTATE_H
#define BAXTER_CORE_MSGS_MESSAGE_NAVIGATORSTATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace baxter_core_msgs
{
template <class ContainerAllocator>
struct NavigatorState_
{
  typedef NavigatorState_<ContainerAllocator> Type;

  NavigatorState_()
    : names()
    , buttons()
    , wheel(0)
    , lights()  {
    }
  NavigatorState_(const ContainerAllocator& _alloc)
    : names(_alloc)
    , buttons(_alloc)
    , wheel(0)
    , lights(_alloc)  {
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _names_type;
  _names_type names;

   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _buttons_type;
  _buttons_type buttons;

   typedef uint8_t _wheel_type;
  _wheel_type wheel;

   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _lights_type;
  _lights_type lights;




  typedef boost::shared_ptr< ::baxter_core_msgs::NavigatorState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::baxter_core_msgs::NavigatorState_<ContainerAllocator> const> ConstPtr;

}; // struct NavigatorState_

typedef ::baxter_core_msgs::NavigatorState_<std::allocator<void> > NavigatorState;

typedef boost::shared_ptr< ::baxter_core_msgs::NavigatorState > NavigatorStatePtr;
typedef boost::shared_ptr< ::baxter_core_msgs::NavigatorState const> NavigatorStateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::baxter_core_msgs::NavigatorState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::baxter_core_msgs::NavigatorState_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace baxter_core_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/jade/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/jade/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/jade/share/geometry_msgs/cmake/../msg'], 'baxter_core_msgs': ['/home/chris/jade/rethink_ws/src/baxter_common/baxter_core_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::baxter_core_msgs::NavigatorState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::baxter_core_msgs::NavigatorState_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::baxter_core_msgs::NavigatorState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::baxter_core_msgs::NavigatorState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::baxter_core_msgs::NavigatorState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::baxter_core_msgs::NavigatorState_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::baxter_core_msgs::NavigatorState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "626a2401ea06bafc2f1ecf16d05f1675";
  }

  static const char* value(const ::baxter_core_msgs::NavigatorState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x626a2401ea06bafcULL;
  static const uint64_t static_value2 = 0x2f1ecf16d05f1675ULL;
};

template<class ContainerAllocator>
struct DataType< ::baxter_core_msgs::NavigatorState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "baxter_core_msgs/NavigatorState";
  }

  static const char* value(const ::baxter_core_msgs::NavigatorState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::baxter_core_msgs::NavigatorState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# buttons\n\
string[] names\n\
bool[] buttons\n\
\n\
# wheel position\n\
uint8   wheel\n\
\n\
# true if the light is on, false if not\n\
# lights map to button names\n\
bool[] lights\n\
";
  }

  static const char* value(const ::baxter_core_msgs::NavigatorState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::baxter_core_msgs::NavigatorState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.names);
      stream.next(m.buttons);
      stream.next(m.wheel);
      stream.next(m.lights);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct NavigatorState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::baxter_core_msgs::NavigatorState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::baxter_core_msgs::NavigatorState_<ContainerAllocator>& v)
  {
    s << indent << "names[]" << std::endl;
    for (size_t i = 0; i < v.names.size(); ++i)
    {
      s << indent << "  names[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.names[i]);
    }
    s << indent << "buttons[]" << std::endl;
    for (size_t i = 0; i < v.buttons.size(); ++i)
    {
      s << indent << "  buttons[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.buttons[i]);
    }
    s << indent << "wheel: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.wheel);
    s << indent << "lights[]" << std::endl;
    for (size_t i = 0; i < v.lights.size(); ++i)
    {
      s << indent << "  lights[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.lights[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // BAXTER_CORE_MSGS_MESSAGE_NAVIGATORSTATE_H
