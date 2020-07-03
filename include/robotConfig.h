#ifndef _ROBOT_CONFIG_H_
#define _ROBOT_CONFIG_H_

#define PROS_USE_SIMPLE_NAMES
#define PROS_USE_LITERALS

#include "api.h"
#include "okapi/api.hpp"

//global variables
using namespace okapi;
extern Controller control;
extern Potentiometer liftPot;

//ports
#define LFDRIVE 55
#define LBDRIVE 66
#define RFDRIVE 55
#define RBDRIVE 11
#define LROLLER 11
#define RROLLER 11
#define LIFT 22

#define LIFTPOT 'H'

#endif
