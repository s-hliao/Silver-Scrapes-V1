#include "main.h"

Motor lift(LIFT, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Potentiometer LiftPot(LIFTPOT);


void liftOp(void*params){
  while(true){
    if(control.getDigital(ControllerDigital::L2)){
      lift.moveVelocity(200);
    } else if(control.getDigital(ControllerDigital::L1)){
      lift.moveVelocity(-200);
    } else{
      lift.moveVelocity(0);
    }
    pros::Task::delay(10);
  }
}
