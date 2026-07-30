// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from teleop_interface:msg/Teleop.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "teleop_interface/msg/teleop.hpp"


#ifndef TELEOP_INTERFACE__MSG__DETAIL__TELEOP__STRUCT_HPP_
#define TELEOP_INTERFACE__MSG__DETAIL__TELEOP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_buffer/buffer.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__teleop_interface__msg__Teleop __attribute__((deprecated))
#else
# define DEPRECATED__teleop_interface__msg__Teleop __declspec(deprecated)
#endif

namespace teleop_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Teleop_
{
  using Type = Teleop_<ContainerAllocator>;

  explicit Teleop_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->direction = "";
    }
  }

  explicit Teleop_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : direction(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->direction = "";
    }
  }

  // field types and members
  using _direction_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _direction_type direction;

  // setters for named parameter idiom
  Type & set__direction(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->direction = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    teleop_interface::msg::Teleop_<ContainerAllocator> *;
  using ConstRawPtr =
    const teleop_interface::msg::Teleop_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<teleop_interface::msg::Teleop_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<teleop_interface::msg::Teleop_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      teleop_interface::msg::Teleop_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<teleop_interface::msg::Teleop_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      teleop_interface::msg::Teleop_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<teleop_interface::msg::Teleop_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<teleop_interface::msg::Teleop_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<teleop_interface::msg::Teleop_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__teleop_interface__msg__Teleop
    std::shared_ptr<teleop_interface::msg::Teleop_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__teleop_interface__msg__Teleop
    std::shared_ptr<teleop_interface::msg::Teleop_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Teleop_ & other) const
  {
    if (this->direction != other.direction) {
      return false;
    }
    return true;
  }
  bool operator!=(const Teleop_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Teleop_

// alias to use template instance with default allocator
using Teleop =
  teleop_interface::msg::Teleop_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace teleop_interface

#endif  // TELEOP_INTERFACE__MSG__DETAIL__TELEOP__STRUCT_HPP_
