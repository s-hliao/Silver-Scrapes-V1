#include "main.h"

Controller control(ControllerId::master);

void opcontrol(){
  	pros::Task driveT(driveOp, (void*)"PROS", TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "Drive Control");
    pros::Task intakeT(intakeOp, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Intake Control");
    pros::Task flywheelT(flywheelOp, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Flywheel Control");
<<<<<<< HEAD
=======
    //pros::Task debugT(debugOp, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Debug");
>>>>>>> 511d33cef62f48d1d51f55004cb282ea94b5a5ac
}
