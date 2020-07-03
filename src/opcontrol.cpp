#include "main.h"

Controller control(ControllerId::master);

void opcontrol(){

  	pros::Task driveT(driveOp, (void*)"PROS", TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "Drive Control");
    pros::Task rollerT(rollerOp, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Roller Control");
    pros::Task liftT(liftOp, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Lift Control");
}
