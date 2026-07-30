#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to teleop_interface__msg__Teleop

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Teleop {

    // This member is not documented.
    #[allow(missing_docs)]
    pub direction: std::string::String,

}



impl Default for Teleop {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Teleop::default())
  }
}

impl rosidl_runtime_rs::Message for Teleop {
  type RmwMsg = super::msg::rmw::Teleop;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        direction: msg.direction.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        direction: msg.direction.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      direction: msg.direction.to_string(),
    }
  }
}


