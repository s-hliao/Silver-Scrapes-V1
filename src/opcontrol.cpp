#include "main.h"

Controller control(ControllerId::master);

void debugOp(void*params){
  while(true){
    printDebug(SideText[autoSide]);
    printDebug(" ");
    printLnDebug(ModeText[autoMode]);

    pros::Task::delay(2000);
  }

}

void opcontrol(){
  	pros::Task driveT(driveOp, (void*)"PROS", TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "Drive Control");
    pros::Task intakeT(intakeOp, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Intake Control");
    pros::Task flywheelT(flywheelOp, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Flywheel Control");
    pros::Task debugT(debugOp, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Debug");
}
