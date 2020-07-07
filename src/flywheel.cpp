#include "main.h"
#include "opcontrol.hpp"

using namespace okapi;

Motor roller(ROLLER, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor flywheel(FLYWHEEL, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

void flywheelOp(void*params){
  while(true){
    if(control.getDigital(ControllerDigital::L2)){
      roller.moveVelocity(200);
      flywheel.moveVelocity(200);
    } else if(control.getDigital(ControllerDigital::L1)){
      roller.moveVelocity(-200);
      flywheel.moveVelocity(-200);
    } else{
      roller.moveVelocity(0);
      flywheel.moveVelocity(25);
    }
    pros::Task::delay(10);
  }
}
