// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from teleop_interface:msg/Teleop.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "teleop_interface/msg/teleop.hpp"


#ifndef TELEOP_INTERFACE__MSG__DETAIL__TELEOP__BUILDER_HPP_
#define TELEOP_INTERFACE__MSG__DETAIL__TELEOP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "teleop_interface/msg/detail/teleop__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace teleop_interface
{

namespace msg
{

namespace builder
{

class Init_Teleop_direction
{
public:
  Init_Teleop_direction()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::teleop_interface::msg::Teleop direction(::teleop_interface::msg::Teleop::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return std::move(msg_);
  }

private:
  ::teleop_interface::msg::Teleop msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::teleop_interface::msg::Teleop>()
{
  return teleop_interface::msg::builder::Init_Teleop_direction();
}

}  // namespace teleop_interface

#endif  // TELEOP_INTERFACE__MSG__DETAIL__TELEOP__BUILDER_HPP_
