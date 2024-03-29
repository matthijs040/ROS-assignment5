// Generated by gencpp from file assignment5/Triangle.msg
// DO NOT EDIT!


#ifndef ASSIGNMENT5_MESSAGE_TRIANGLE_H
#define ASSIGNMENT5_MESSAGE_TRIANGLE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace assignment5
{
template <class ContainerAllocator>
struct Triangle_
{
  typedef Triangle_<ContainerAllocator> Type;

  Triangle_()
    : sideLength(0.0)
    , cw(false)  {
    }
  Triangle_(const ContainerAllocator& _alloc)
    : sideLength(0.0)
    , cw(false)  {
  (void)_alloc;
    }



   typedef float _sideLength_type;
  _sideLength_type sideLength;

   typedef uint8_t _cw_type;
  _cw_type cw;





  typedef boost::shared_ptr< ::assignment5::Triangle_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::assignment5::Triangle_<ContainerAllocator> const> ConstPtr;

}; // struct Triangle_

typedef ::assignment5::Triangle_<std::allocator<void> > Triangle;

typedef boost::shared_ptr< ::assignment5::Triangle > TrianglePtr;
typedef boost::shared_ptr< ::assignment5::Triangle const> TriangleConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::assignment5::Triangle_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::assignment5::Triangle_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace assignment5

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'assignment5': ['/mnt/c/Users/Matthew/Documents/FHICT/6ROS/catkin_ws/src/assignment5/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::assignment5::Triangle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::assignment5::Triangle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::assignment5::Triangle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::assignment5::Triangle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::assignment5::Triangle_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::assignment5::Triangle_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::assignment5::Triangle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "431f3f9588f8a77c455295381a353b46";
  }

  static const char* value(const ::assignment5::Triangle_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x431f3f9588f8a77cULL;
  static const uint64_t static_value2 = 0x455295381a353b46ULL;
};

template<class ContainerAllocator>
struct DataType< ::assignment5::Triangle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "assignment5/Triangle";
  }

  static const char* value(const ::assignment5::Triangle_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::assignment5::Triangle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 sideLength\n"
"bool cw\n"
;
  }

  static const char* value(const ::assignment5::Triangle_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::assignment5::Triangle_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.sideLength);
      stream.next(m.cw);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Triangle_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::assignment5::Triangle_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::assignment5::Triangle_<ContainerAllocator>& v)
  {
    s << indent << "sideLength: ";
    Printer<float>::stream(s, indent + "  ", v.sideLength);
    s << indent << "cw: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cw);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ASSIGNMENT5_MESSAGE_TRIANGLE_H
