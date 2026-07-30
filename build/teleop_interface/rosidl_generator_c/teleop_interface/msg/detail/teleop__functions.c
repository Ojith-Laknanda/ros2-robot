// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from teleop_interface:msg/Teleop.idl
// generated code does not contain a copyright notice
#include "teleop_interface/msg/detail/teleop__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `direction`
#include "rosidl_runtime_c/string_functions.h"

bool
teleop_interface__msg__Teleop__init(teleop_interface__msg__Teleop * msg)
{
  if (!msg) {
    return false;
  }
  // direction
  if (!rosidl_runtime_c__String__init(&msg->direction)) {
    teleop_interface__msg__Teleop__fini(msg);
    return false;
  }
  return true;
}

void
teleop_interface__msg__Teleop__fini(teleop_interface__msg__Teleop * msg)
{
  if (!msg) {
    return;
  }
  // direction
  rosidl_runtime_c__String__fini(&msg->direction);
}

bool
teleop_interface__msg__Teleop__are_equal(const teleop_interface__msg__Teleop * lhs, const teleop_interface__msg__Teleop * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // direction
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->direction), &(rhs->direction)))
  {
    return false;
  }
  return true;
}

bool
teleop_interface__msg__Teleop__copy(
  const teleop_interface__msg__Teleop * input,
  teleop_interface__msg__Teleop * output)
{
  if (!input || !output) {
    return false;
  }
  // direction
  if (!rosidl_runtime_c__String__copy(
      &(input->direction), &(output->direction)))
  {
    return false;
  }
  return true;
}

teleop_interface__msg__Teleop *
teleop_interface__msg__Teleop__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  teleop_interface__msg__Teleop * msg = (teleop_interface__msg__Teleop *)allocator.allocate(sizeof(teleop_interface__msg__Teleop), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(teleop_interface__msg__Teleop));
  bool success = teleop_interface__msg__Teleop__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
teleop_interface__msg__Teleop__destroy(teleop_interface__msg__Teleop * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    teleop_interface__msg__Teleop__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
teleop_interface__msg__Teleop__Sequence__init(teleop_interface__msg__Teleop__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  teleop_interface__msg__Teleop * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(teleop_interface__msg__Teleop)) {
      return false;
    }
    data = (teleop_interface__msg__Teleop *)allocator.zero_allocate(size, sizeof(teleop_interface__msg__Teleop), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = teleop_interface__msg__Teleop__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        teleop_interface__msg__Teleop__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
teleop_interface__msg__Teleop__Sequence__fini(teleop_interface__msg__Teleop__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      teleop_interface__msg__Teleop__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

teleop_interface__msg__Teleop__Sequence *
teleop_interface__msg__Teleop__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  teleop_interface__msg__Teleop__Sequence * array = (teleop_interface__msg__Teleop__Sequence *)allocator.allocate(sizeof(teleop_interface__msg__Teleop__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = teleop_interface__msg__Teleop__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
teleop_interface__msg__Teleop__Sequence__destroy(teleop_interface__msg__Teleop__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    teleop_interface__msg__Teleop__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
teleop_interface__msg__Teleop__Sequence__are_equal(const teleop_interface__msg__Teleop__Sequence * lhs, const teleop_interface__msg__Teleop__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!teleop_interface__msg__Teleop__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
teleop_interface__msg__Teleop__Sequence__copy(
  const teleop_interface__msg__Teleop__Sequence * input,
  teleop_interface__msg__Teleop__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(teleop_interface__msg__Teleop)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(teleop_interface__msg__Teleop);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    teleop_interface__msg__Teleop * data =
      (teleop_interface__msg__Teleop *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!teleop_interface__msg__Teleop__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          teleop_interface__msg__Teleop__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!teleop_interface__msg__Teleop__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
