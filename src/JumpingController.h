#pragma once

#include <mc_control/mc_controller.h>
#include <mc_control/fsm/Controller.h>

#include "api.h"

struct JumpingController_DLLAPI JumpingController : public mc_control::fsm::Controller
{
  JumpingController(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config);

  bool run() override;

  void reset(const mc_control::ControllerResetData & reset_data) override;

  double dt_ = 0.005;

  bool reset_rdy = false;

  bool isTicker = true;

  size_t flight_count = 0;

};