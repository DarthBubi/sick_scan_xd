#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/RadarScan.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_RADARSCAN_H
#define SICK_SCAN_MESSAGE_RADARSCAN_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <sick_scan/RadarPreHeader.h>
#include <sensor_msgs/PointCloud2.h>
#include <sick_scan/RadarObject.h>

namespace sick_scan
{
template <class ContainerAllocator>
struct RadarScan_
{
  typedef RadarScan_<ContainerAllocator> Type;

  RadarScan_()
    : header()
    , radarpreheader()
    , targets()
    , objects()  {
    }
  RadarScan_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , radarpreheader(_alloc)
    , targets(_alloc)
    , objects(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::sick_scan::RadarPreHeader_<ContainerAllocator>  _radarpreheader_type;
  _radarpreheader_type radarpreheader;

   typedef  ::sensor_msgs::PointCloud2_<ContainerAllocator>  _targets_type;
  _targets_type targets;

   typedef std::vector< ::sick_scan::RadarObject_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::sick_scan::RadarObject_<ContainerAllocator> >::other >  _objects_type;
  _objects_type objects;





  typedef std::shared_ptr< ::sick_scan::RadarScan_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::RadarScan_<ContainerAllocator> const> ConstPtr;

}; // struct RadarScan_

typedef ::sick_scan::RadarScan_<std::allocator<void> > RadarScan;

typedef std::shared_ptr< ::sick_scan::RadarScan > RadarScanPtr;
typedef std::shared_ptr< ::sick_scan::RadarScan const> RadarScanConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::RadarScan_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::RadarScan_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::RadarScan_<ContainerAllocator1> & lhs, const ::sick_scan::RadarScan_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.radarpreheader == rhs.radarpreheader &&
    lhs.targets == rhs.targets &&
    lhs.objects == rhs.objects;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::RadarScan_<ContainerAllocator1> & lhs, const ::sick_scan::RadarScan_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::RadarScan_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::RadarScan_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::RadarScan_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::RadarScan_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::RadarScan_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::RadarScan_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::RadarScan_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3522a556afdfee3cdd216082c57b4a98";
  }

  static const char* value(const ::sick_scan::RadarScan_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3522a556afdfee3cULL;
  static const uint64_t static_value2 = 0xdd216082c57b4a98ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::RadarScan_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/RadarScan";
  }

  static const char* value(const ::sick_scan::RadarScan_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::RadarScan_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#\n"
"# The message is divided into three parts:\n"
"# 1. Header: containing information about general radar parameters\n"
"# 2. RawTargets: List of targets containing maximum values in the range-doppler-matrix - used for tracking\n"
"# 3. Objects: List of objects generated by the internal tracking algorithm - based on raw targets\n"
"# ROS-1:\n"
"#Header header\n"
"#RadarPreHeader radarPreHeader\n"
"# ROS-2:\n"
"std_msgs/Header header\n"
"RadarPreHeader radarpreheader\n"
"sensor_msgs/PointCloud2 targets\n"
"sick_scan/RadarObject[] objects\n"
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
"\n"
"================================================================================\n"
"MSG: sick_scan/RadarPreHeader\n"
"# Version information for this whole structure (MeasurementData)\n"
"\n"
"# ROS-1:\n"
"#uint16 uiVersionNo\n"
"#sick_scan/RadarPreHeaderDeviceBlock radarPreHeaderDeviceBlock\n"
"#sick_scan/RadarPreHeaderStatusBlock radarPreHeaderStatusBlock\n"
"#sick_scan/RadarPreHeaderMeasurementParam1Block radarPreHeaderMeasurementParam1Block\n"
"#sick_scan/RadarPreHeaderEncoderBlock[] radarPreHeaderArrayEncoderBlock\n"
"\n"
"# ROS-2:\n"
"uint16 uiversionno\n"
"sick_scan/RadarPreHeaderDeviceBlock radarpreheaderdeviceblock\n"
"sick_scan/RadarPreHeaderStatusBlock radarpreheaderstatusblock\n"
"sick_scan/RadarPreHeaderMeasurementParam1Block radarpreheadermeasurementparam1block\n"
"sick_scan/RadarPreHeaderEncoderBlock[] radarpreheaderarrayencoderblock\n"
"\n"
"================================================================================\n"
"MSG: sick_scan/RadarPreHeaderDeviceBlock\n"
"#\n"
"#\n"
"#\n"
"#\n"
"\n"
"# ROS-1:\n"
"#uint32 uiIdent             # Logical number of the device\"\n"
"#uint32 udiSerialNo         # Serial number of the device\n"
"#bool bDeviceError          # State of the device\n"
"#bool bContaminationWarning # Contamination Warning\n"
"#bool bContaminationError   # Contamination Error\n"
"\n"
"# ROS-2:\n"
"uint32 uiident             # Logical number of the device\"\n"
"uint32 udiserialno         # Serial number of the device\n"
"bool bdeviceerror          # State of the device\n"
"bool bcontaminationwarning # Contamination Warning\n"
"bool bcontaminationerror   # Contamination Error\n"
"\n"
"================================================================================\n"
"MSG: sick_scan/RadarPreHeaderStatusBlock\n"
"#\n"
"#\n"
"#\n"
"# ROS-1:\n"
"#uint32 uiTelegramCount # telegram number\n"
"#uint32 uiCycleCount # \"scan number\"\n"
"#uint32 udiSystemCountScan # system time since power on of scan gen. [us]\n"
"#uint32 udiSystemCountTransmit # system time since power on of scan transmission [us]\n"
"#uint16 uiInputs # state of digital inputs\n"
"#uint16 uiOutputs # state of digital outputs\n"
"\n"
"# ROS-2:\n"
"uint32 uitelegramcount # telegram number\n"
"uint32 uicyclecount # \"scan number\"\n"
"uint32 udisystemcountscan # system time since power on of scan gen. [us]\n"
"uint32 udisystemcounttransmit # system time since power on of scan transmission [us]\n"
"uint16 uiinputs # state of digital inputs\n"
"uint16 uioutputs # state of digital outputs\n"
"\n"
"================================================================================\n"
"MSG: sick_scan/RadarPreHeaderMeasurementParam1Block\n"
"# ROS-1:\n"
"#uint32 uiCycleDuration # Time in microseconds to detect this items\n"
"#uint32 uiNoiseLevel # [1/100dB]\n"
"# ROS-2:\n"
"uint32 uicycleduration # Time in microseconds to detect this items\n"
"uint32 uinoiselevel # [1/100dB]\n"
"\n"
"================================================================================\n"
"MSG: sick_scan/RadarPreHeaderEncoderBlock\n"
"# Array with connected encoder sensors\n"
"# ROS-1:\n"
"#uint32 udiEncoderPos  # encoder position [inc]\n"
"#int16 iEncoderSpeed   # encoder speed [inc/mm]\n"
"# ROS-2:\n"
"uint32 udiencoderpos  # encoder position [inc]\n"
"int16 iencoderspeed   # encoder speed [inc/mm]\n"
"\n"
"================================================================================\n"
"MSG: sensor_msgs/PointCloud2\n"
"# This message holds a collection of N-dimensional points, which may\n"
"# contain additional information such as normals, intensity, etc. The\n"
"# point data is stored as a binary blob, its layout described by the\n"
"# contents of the \"fields\" array.\n"
"\n"
"# The point cloud data may be organized 2d (image-like) or 1d\n"
"# (unordered). Point clouds organized as 2d images may be produced by\n"
"# camera depth sensors such as stereo or time-of-flight.\n"
"\n"
"# Time of sensor data acquisition, and the coordinate frame ID (for 3d\n"
"# points).\n"
"Header header\n"
"\n"
"# 2D structure of the point cloud. If the cloud is unordered, height is\n"
"# 1 and width is the length of the point cloud.\n"
"uint32 height\n"
"uint32 width\n"
"\n"
"# Describes the channels and their layout in the binary data blob.\n"
"PointField[] fields\n"
"\n"
"bool    is_bigendian # Is this data bigendian?\n"
"uint32  point_step   # Length of a point in bytes\n"
"uint32  row_step     # Length of a row in bytes\n"
"uint8[] data         # Actual point data, size is (row_step*height)\n"
"\n"
"bool is_dense        # True if there are no invalid points\n"
"\n"
"================================================================================\n"
"MSG: sensor_msgs/PointField\n"
"# This message holds the description of one point entry in the\n"
"# PointCloud2 message format.\n"
"uint8 INT8    = 1\n"
"uint8 UINT8   = 2\n"
"uint8 INT16   = 3\n"
"uint8 UINT16  = 4\n"
"uint8 INT32   = 5\n"
"uint8 UINT32  = 6\n"
"uint8 FLOAT32 = 7\n"
"uint8 FLOAT64 = 8\n"
"\n"
"string name      # Name of field\n"
"uint32 offset    # Offset from start of point struct\n"
"uint8  datatype  # Datatype enumeration, see above\n"
"uint32 count     # How many elements in the field\n"
"\n"
"================================================================================\n"
"MSG: sick_scan/RadarObject\n"
"int32 id\n"
"\n"
"# ROS-1:\n"
"time tracking_time                          # since when the object is tracked\n"
"time last_seen\n"
"\n"
"# ROS-2:\n"
"#builtin_interfaces/Time tracking_time        # since when the object is tracked\n"
"#builtin_interfaces/Time last_seen\n"
"\n"
"geometry_msgs/TwistWithCovariance velocity\n"
"\n"
"geometry_msgs/Pose bounding_box_center\n"
"geometry_msgs/Vector3 bounding_box_size\n"
"\n"
"geometry_msgs/PoseWithCovariance object_box_center\n"
"geometry_msgs/Vector3 object_box_size\n"
"\n"
"geometry_msgs/Point[] contour_points\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/TwistWithCovariance\n"
"# This expresses velocity in free space with uncertainty.\n"
"\n"
"Twist twist\n"
"\n"
"# Row-major representation of the 6x6 covariance matrix\n"
"# The orientation parameters use a fixed-axis representation.\n"
"# In order, the parameters are:\n"
"# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n"
"float64[36] covariance\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Twist\n"
"# This expresses velocity in free space broken into its linear and angular parts.\n"
"Vector3  linear\n"
"Vector3  angular\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseWithCovariance\n"
"# This represents a pose in free space with uncertainty.\n"
"\n"
"Pose pose\n"
"\n"
"# Row-major representation of the 6x6 covariance matrix\n"
"# The orientation parameters use a fixed-axis representation.\n"
"# In order, the parameters are:\n"
"# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n"
"float64[36] covariance\n"
;
  }

  static const char* value(const ::sick_scan::RadarScan_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::RadarScan_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.radarpreheader);
      stream.next(m.targets);
      stream.next(m.objects);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RadarScan_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::RadarScan_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::RadarScan_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "radarpreheader: ";
    s << std::endl;
    Printer< ::sick_scan::RadarPreHeader_<ContainerAllocator> >::stream(s, indent + "  ", v.radarpreheader);
    s << indent << "targets: ";
    s << std::endl;
    Printer< ::sensor_msgs::PointCloud2_<ContainerAllocator> >::stream(s, indent + "  ", v.targets);
    s << indent << "objects[]" << std::endl;
    for (size_t i = 0; i < v.objects.size(); ++i)
    {
      s << indent << "  objects[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::sick_scan::RadarObject_<ContainerAllocator> >::stream(s, indent + "    ", v.objects[i]);
    }
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_RADARSCAN_H
