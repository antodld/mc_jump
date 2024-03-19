#include "JumpingController_Initial.h"

#include "../JumpingController.h"

void JumpingController_Initial::configure(const mc_rtc::Configuration & config)
{
}

void JumpingController_Initial::start(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<JumpingController &>(ctl_);
}

bool JumpingController_Initial::run(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<JumpingController &>(ctl_);
  ctl.getPostureTask(ctl.robot().name())->weight(1);
  ctl.getPostureTask(ctl.robot().name())->stiffness(0.5);
  output("OK");
  return true;
}

void JumpingController_Initial::teardown(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<JumpingController &>(ctl_);
}

EXPORT_SINGLE_STATE("JumpingController_Initial", JumpingController_Initial)
