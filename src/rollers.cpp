#include "main.h"

Motor LRoller(LRollerPort, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
Motor RRoller(RRollerPort, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);

void rollerOp(void*params){
  while(true){
    if(control.get_digital(DIGITAL_R2)){
        LRoller.move_velocity(200);
        RRoller.move_velocity(200);
    } else if(control.get_digital(DIGITAL_R1)){
        LRoller.move_velocity(-200);
        RRoller.move_velocity(-200);
    } else{
        LRoller.move_velocity(0);
        RRoller.move_velocity(0);
    }
  }
}
