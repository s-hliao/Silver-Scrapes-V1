#ifndef _ROBOT_STATE_H_
#define _ROBOT_STATE_H_

#include "enums.h"

extern Side autoSide;
extern Mode autoMode;
extern bool autoRun;

void printDebug(const char* txt);
void printLnDebug(const char* txt);

#endif
