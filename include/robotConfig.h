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
#define LFDRIVE 1
#define LBDRIVE 2
#define RFDRIVE 3
#define RBDRIVE 15
#define LINTAKE 5
#define RINTAKE 6
#define ROLLER 7
#define FLYWHEEL 8

#define LQUAD1 'A'
#define LQUAD2 'B'
#define RQUAD1 'C'
#define RQUAD2 'D'
#define MQUAD1 'E'
#define MQUAD2 'F'

// #define LIFTPOT 'H'

#endif
