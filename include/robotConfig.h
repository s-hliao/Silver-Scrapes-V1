#ifndef _ROBOT_CONFIG_H_
#define _ROBOT_CONFIG_H_

#define PROS_USE_SIMPLE_NAMES
#define PROS_USE_LITERALS

#include "api.h"
#include "pros/motors.h"

//ports
#define LFDrivePort 55
#define LBDrivePort 66
#define RFDrivePort 55
#define RBDrivePort 11
#define LRollerPort 11
#define RRollerPort 11
#define LiftPort 22

#define LiftPotPort 'H'

 using namespace pros;
 using namespace pros::literals;
// using namespace okapi;

//global variables
extern Controller control;
extern ADIPotentiometer liftPot;

#endif
