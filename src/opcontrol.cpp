#include "main.h"
#include "drive.hpp"
#include "flywheel.hpp"
#include "intake.hpp"

Controller control(ControllerId::master);

void opcontrol(){
  	pros::Task driveT(driveOp, (void*)"PROS", TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "Drive Control");
    pros::Task intakeT(intakeOp, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Intake Control");
    pros::Task flywheelT(flywheelOp, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Flywheel Control");
}
