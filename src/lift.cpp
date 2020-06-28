#include "main.h"

Motor lift(LiftPort, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
ADIPotentiometer LiftPot(LiftPotPort);


void liftOp(void*params){
  while(true){
    if(control.get_digital(DIGITAL_L1)){
      lift.move_velocity(200);
    } else if(control.get_digital(DIGITAL_R1)){
      lift.move_velocity(-200);
    } else{
      lift.move_velocity(0);
    }
  }
}
