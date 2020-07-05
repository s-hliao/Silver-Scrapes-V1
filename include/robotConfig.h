#ifndef _ROBOT_CONFIG_H_
#define _ROBOT_CONFIG_H_

#define PROS_USE_SIMPLE_NAMES
#define PROS_USE_LITERALS

#include "api.h"
#include "okapi/api.hpp"

//global variables
using namespace okapi;
extern Controller control;
extern Motor LFDrive;
extern Motor LBDrive;
extern Motor RFDrive;
extern Motor RBDrive;
extern Motor LIntake;
extern Motor RIntake;
extern Motor roller;
extern Motor flywheel;


//ports
#define LFDRIVE 55
#define LBDRIVE 66
#define RFDRIVE 55
#define RBDRIVE 11
#define LINTAKE 11
#define RINTAKE 11
#define ROLLER 22
#define FLYWHEEL 15

// #define LIFTPOT 'H'

#endif
