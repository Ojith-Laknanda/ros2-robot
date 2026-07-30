// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from teleop_interface:msg/Teleop.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "teleop_interface/msg/teleop.hpp"


#ifndef TELEOP_INTERFACE__MSG__DETAIL__TELEOP__TRAITS_HPP_
#define TELEOP_INTERFACE__MSG__DETAIL__TELEOP__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "teleop_interface/msg/detail/teleop__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace teleop_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Teleop & msg,
  std::ostream & out)
{
  out << "{";
  // member: direction
  {
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Teleop & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Teleop & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, teleop_interface::msg::Teleop>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).direction);
}

}  // namespace msg

}  // namespace teleop_interface

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<teleop_interface::msg::Teleop>()
{
  return "teleop_interface::msg::Teleop";
}

template<>
constexpr const char * name<teleop_interface::msg::Teleop>()
{
  return "teleop_interface/msg/Teleop";
}

template<>
struct has_fixed_size<teleop_interface::msg::Teleop>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<teleop_interface::msg::Teleop>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<teleop_interface::msg::Teleop>
  : std::true_type {};

template<>
struct MessageTraits<teleop_interface::msg::Teleop>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "direction",
  };
};

}  // namespace rosidl_generator_traits

#endif  // TELEOP_INTERFACE__MSG__DETAIL__TELEOP__TRAITS_HPP_
