#include "main.h"

Motor LRoller(LROLLER, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor RRoller(RROLLER, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

void rollerOp(void*params){
  while(true){
    if(control.getDigital(ControllerDigital::R2)){
        LRoller.moveVelocity(200);
        RRoller.moveVelocity(200);
    } else if(control.getDigital(ControllerDigital::R1)){
        LRoller.moveVelocity(-200);
        RRoller.moveVelocity(-200);
    } else{
        LRoller.moveVelocity(0);
        RRoller.moveVelocity(0);
    }
    pros::Task::delay(10);
  }
}
