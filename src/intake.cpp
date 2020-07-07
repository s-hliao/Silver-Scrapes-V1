#include "main.h"
#include "opcontrol.hpp"

using namespace okapi;

Motor LIntake(LINTAKE, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor RIntake(RINTAKE, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

void intakeOp(void*params){
  while(true){
    if(control.getDigital(ControllerDigital::L2)){
      LIntake.moveVelocity(200);
      RIntake.moveVelocity(200);
    } else if(control.getDigital(ControllerDigital::L1)){
      LIntake.moveVelocity(-200);
      RIntake.moveVelocity(-200);
    } else{
      LIntake.moveVelocity(0);
      RIntake.moveVelocity(0);
    }
    pros::Task::delay(10);
  }
}
