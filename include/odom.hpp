#ifndef _PROS_ODOM_H_
#define _PROS_ODOM_H_

#include "robotConfig.h"
extern std::shared_ptr<Odometry> odom;

double wrap(double);
QAngle wrap(QAngle);

#endif
