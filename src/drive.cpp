#include "main.h"
Motor LFDrive(LFDrivePort, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES);
Motor RFDrive(RFDrivePort, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
Motor LBDrive(LBDrivePort, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES);
Motor RBDrive(RBDrivePort, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);

void driveOp(void*params){
  LFDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
  RFDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
  LBDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
  RBDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);

  while(true){
    int LPow = control.get_analog(ANALOG_LEFT_Y)*600/127;
    int RPow = control.get_analog(ANALOG_RIGHT_Y)*600/127;
    LFDrive.move_velocity(LPow);
    LBDrive.move_velocity(LPow);
    RFDrive.move_velocity(RPow);
    RBDrive.move_velocity(RPow);
  }
}
