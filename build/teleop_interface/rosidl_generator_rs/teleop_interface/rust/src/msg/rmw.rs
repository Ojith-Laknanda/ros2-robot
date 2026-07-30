#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "teleop_interface__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__teleop_interface__msg__Teleop() -> *const std::ffi::c_void;
}

#[link(name = "teleop_interface__rosidl_generator_c")]
extern "C" {
    fn teleop_interface__msg__Teleop__init(msg: *mut Teleop) -> bool;
    fn teleop_interface__msg__Teleop__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Teleop>, size: usize) -> bool;
    fn teleop_interface__msg__Teleop__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Teleop>);
    fn teleop_interface__msg__Teleop__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Teleop>, out_seq: *mut rosidl_runtime_rs::Sequence<Teleop>) -> bool;
}

// Corresponds to teleop_interface__msg__Teleop
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Teleop {

    // This member is not documented.
    #[allow(missing_docs)]
    pub direction: rosidl_runtime_rs::String,

}



impl Default for Teleop {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !teleop_interface__msg__Teleop__init(&mut msg as *mut _) {
        panic!("Call to teleop_interface__msg__Teleop__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Teleop {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { teleop_interface__msg__Teleop__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { teleop_interface__msg__Teleop__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { teleop_interface__msg__Teleop__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Teleop {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Teleop where Self: Sized {
  const TYPE_NAME: &'static str = "teleop_interface/msg/Teleop";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__teleop_interface__msg__Teleop() }
  }
}


