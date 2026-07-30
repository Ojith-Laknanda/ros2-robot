// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from teleop_interface:msg/Teleop.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "teleop_interface/msg/teleop.h"


#ifndef TELEOP_INTERFACE__MSG__DETAIL__TELEOP__STRUCT_H_
#define TELEOP_INTERFACE__MSG__DETAIL__TELEOP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'direction'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Teleop in the package teleop_interface.
typedef struct teleop_interface__msg__Teleop
{
  rosidl_runtime_c__String direction;
} teleop_interface__msg__Teleop;

// Struct for a sequence of teleop_interface__msg__Teleop.
typedef struct teleop_interface__msg__Teleop__Sequence
{
  teleop_interface__msg__Teleop * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} teleop_interface__msg__Teleop__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TELEOP_INTERFACE__MSG__DETAIL__TELEOP__STRUCT_H_
