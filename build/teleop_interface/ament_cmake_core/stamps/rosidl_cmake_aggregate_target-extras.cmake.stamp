# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target teleop_interface::teleop_interface
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${teleop_interface_TARGETS}.
if(teleop_interface_TARGETS AND NOT TARGET teleop_interface::teleop_interface)
  add_library(teleop_interface::teleop_interface INTERFACE IMPORTED)
  set_target_properties(teleop_interface::teleop_interface PROPERTIES
    INTERFACE_LINK_LIBRARIES "${teleop_interface_TARGETS}")
endif()
