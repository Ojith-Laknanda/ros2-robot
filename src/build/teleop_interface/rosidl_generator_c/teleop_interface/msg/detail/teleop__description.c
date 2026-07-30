// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from teleop_interface:msg/Teleop.idl
// generated code does not contain a copyright notice

#include "teleop_interface/msg/detail/teleop__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_teleop_interface
const rosidl_type_hash_t *
teleop_interface__msg__Teleop__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc6, 0xb4, 0x6d, 0x8d, 0xe1, 0x90, 0x2d, 0x21,
      0x87, 0x64, 0x39, 0x14, 0xed, 0xd1, 0x0d, 0x95,
      0xc2, 0x43, 0x74, 0xff, 0x4a, 0x25, 0xca, 0x2a,
      0x90, 0x8c, 0xe5, 0xfc, 0xec, 0x12, 0x5e, 0xf8,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char teleop_interface__msg__Teleop__TYPE_NAME[] = "teleop_interface/msg/Teleop";

// Define type names, field names, and default values
static char teleop_interface__msg__Teleop__FIELD_NAME__direction[] = "direction";

static rosidl_runtime_c__type_description__Field teleop_interface__msg__Teleop__FIELDS[] = {
  {
    {teleop_interface__msg__Teleop__FIELD_NAME__direction, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
teleop_interface__msg__Teleop__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {teleop_interface__msg__Teleop__TYPE_NAME, 27, 27},
      {teleop_interface__msg__Teleop__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string direction";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
teleop_interface__msg__Teleop__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {teleop_interface__msg__Teleop__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 17, 17},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
teleop_interface__msg__Teleop__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *teleop_interface__msg__Teleop__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
