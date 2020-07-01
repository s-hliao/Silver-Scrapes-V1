#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES
#define PROS_USE_LITERALS

#include "pros/motors.h"
#include "pros/apix.h"
#include "okapi/api.hpp"
#include "robotConfig.h"

#include "drive.hpp"
#include "rollers.hpp"
#include "lift.hpp"

//#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
