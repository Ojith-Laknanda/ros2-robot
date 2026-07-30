// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from teleop_interface:msg/Teleop.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "teleop_interface/msg/detail/teleop__functions.h"
#include "teleop_interface/msg/detail/teleop__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace teleop_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Teleop_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) teleop_interface::msg::Teleop(_init);
}

void Teleop_fini_function(void * message_memory)
{
  auto typed_message = static_cast<teleop_interface::msg::Teleop *>(message_memory);
  typed_message->~Teleop();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Teleop_message_member_array[1] = {
  {
    "direction",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(teleop_interface::msg::Teleop, direction),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr,  // resize(index) function pointer
    false  // is_rosidl_buffer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Teleop_message_members = {
  "teleop_interface::msg",  // message namespace
  "Teleop",  // message name
  1,  // number of fields
  sizeof(teleop_interface::msg::Teleop),
  false,  // has_any_key_member_
  Teleop_message_member_array,  // message members
  Teleop_init_function,  // function to initialize message memory (memory has to be allocated)
  Teleop_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Teleop_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Teleop_message_members,
  get_message_typesupport_handle_function,
  &teleop_interface__msg__Teleop__get_type_hash,
  &teleop_interface__msg__Teleop__get_type_description,
  &teleop_interface__msg__Teleop__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace teleop_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<teleop_interface::msg::Teleop>()
{
  return &::teleop_interface::msg::rosidl_typesupport_introspection_cpp::Teleop_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, teleop_interface, msg, Teleop)() {
  return &::teleop_interface::msg::rosidl_typesupport_introspection_cpp::Teleop_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
