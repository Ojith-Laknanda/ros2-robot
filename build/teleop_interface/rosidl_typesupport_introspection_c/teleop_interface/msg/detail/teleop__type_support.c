// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from teleop_interface:msg/Teleop.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "teleop_interface/msg/detail/teleop__rosidl_typesupport_introspection_c.h"
#include "teleop_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "teleop_interface/msg/detail/teleop__functions.h"
#include "teleop_interface/msg/detail/teleop__struct.h"


// Include directives for member types
// Member `direction`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void teleop_interface__msg__Teleop__rosidl_typesupport_introspection_c__Teleop_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  teleop_interface__msg__Teleop__init(message_memory);
}

void teleop_interface__msg__Teleop__rosidl_typesupport_introspection_c__Teleop_fini_function(void * message_memory)
{
  teleop_interface__msg__Teleop__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember teleop_interface__msg__Teleop__rosidl_typesupport_introspection_c__Teleop_message_member_array[1] = {
  {
    "direction",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(teleop_interface__msg__Teleop, direction),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers teleop_interface__msg__Teleop__rosidl_typesupport_introspection_c__Teleop_message_members = {
  "teleop_interface__msg",  // message namespace
  "Teleop",  // message name
  1,  // number of fields
  sizeof(teleop_interface__msg__Teleop),
  false,  // has_any_key_member_
  teleop_interface__msg__Teleop__rosidl_typesupport_introspection_c__Teleop_message_member_array,  // message members
  teleop_interface__msg__Teleop__rosidl_typesupport_introspection_c__Teleop_init_function,  // function to initialize message memory (memory has to be allocated)
  teleop_interface__msg__Teleop__rosidl_typesupport_introspection_c__Teleop_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t teleop_interface__msg__Teleop__rosidl_typesupport_introspection_c__Teleop_message_type_support_handle = {
  0,
  &teleop_interface__msg__Teleop__rosidl_typesupport_introspection_c__Teleop_message_members,
  get_message_typesupport_handle_function,
  &teleop_interface__msg__Teleop__get_type_hash,
  &teleop_interface__msg__Teleop__get_type_description,
  &teleop_interface__msg__Teleop__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_teleop_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, teleop_interface, msg, Teleop)() {
  if (!teleop_interface__msg__Teleop__rosidl_typesupport_introspection_c__Teleop_message_type_support_handle.typesupport_identifier) {
    teleop_interface__msg__Teleop__rosidl_typesupport_introspection_c__Teleop_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &teleop_interface__msg__Teleop__rosidl_typesupport_introspection_c__Teleop_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
