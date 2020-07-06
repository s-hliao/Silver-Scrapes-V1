#ifndef _ROBOT_STATE_H_
#define _ROBOT_STATE_H_

#include "enums.h"

extern Side autoSide;
extern Mode autoMode;
extern bool autoRun;

extern double dp;
extern double di;
extern double dd;
extern double hp;
extern double hi;
extern double hd;
extern double mult;


void printDebug(const char* txt);
void printLnDebug(const char* txt);

#endif
