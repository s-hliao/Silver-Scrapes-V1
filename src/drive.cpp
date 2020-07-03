#include "main.h"
#include "robotState.h"

Motor LFDrive(LFDRIVE, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor RFDrive(RFDRIVE, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor LBDrive(LBDRIVE, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
Motor RBDrive(RBDRIVE, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

void driveOp(void*params){
  LFDrive.setBrakeMode(AbstractMotor::brakeMode::brake);
  RFDrive.setBrakeMode(AbstractMotor::brakeMode::brake);
  LBDrive.setBrakeMode(AbstractMotor::brakeMode::brake);
  RBDrive.setBrakeMode(AbstractMotor::brakeMode::brake);

  while(true){
    int LPow = control.getAnalog(ControllerAnalog::leftY)*600/127;
    int RPow = control.getAnalog(ControllerAnalog::rightY)*600/127;
    LFDrive.moveVelocity(LPow);
    LBDrive.moveVelocity(LPow);
    RFDrive.moveVelocity(RPow);
    RBDrive.moveVelocity(RPow);

    printf("%d", autoSide);
    printf("%d", autoMode);

    pros::Task::delay(500);
  }
}
