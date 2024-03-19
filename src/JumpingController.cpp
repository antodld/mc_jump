#include "JumpingController.h"

JumpingController::JumpingController(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: mc_control::fsm::Controller(rm, dt, config,{mc_solver::QPSolver::Backend::TVM})
{
  dt_ = dt;
  mc_rtc::log::success("JumpingController init done ");
}

bool JumpingController::run()
{
  
  rbd::updateCoMFrame(robot().mb(),robot().mbc(),dt_);
  // Note: if you are using a specific feedback type use that in the calls to `run()`
  bool res = mc_control::fsm::Controller::run();
  if(!res && executor_.state() == "Jump::TakeOff")
  {
    mc_rtc::log::warning("QP failed: switching state");
    executor_.resume("Jump::Flight");
    return mc_control::fsm::Controller::run();
  }
  if(!res)
  {
    mc_rtc::log::warning("QP failed: update robot");
    robot().mbc().q = realRobot().mbc().q;
    robot().mbc().alpha = realRobot().mbc().alpha;
    robot().posW(realRobot().posW());

    return mc_control::fsm::Controller::run();
  }
  // if (executor_.state() == "Jump::Land")
  // {
  //   getPostureTask(robot().name())->stiffness(0);
  //   getPostureTask(robot().name())->damping(1);
  // }
  // else
  // {
  //   getPostureTask(robot().name())->stiffness(0.5);
  // }
  return res;

}

void JumpingController::reset(const mc_control::ControllerResetData & reset_data)
{
  // robot().mbc().gravity *= 0.2;
  rbd::resetCoMFrame(robot().mb(),robot().mbc());

  mc_control::fsm::Controller::reset(reset_data);
}


