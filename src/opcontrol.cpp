#include "main.h"

Controller control (CONTROLLER_MASTER);

void opcontrol(){
  	Task driveT(driveOp, (void*)"PROS", TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "Drive Control");
    Task rollerT(rollerOp, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Roller Control");
    Task liftT(liftOp, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Lift Control");
}
