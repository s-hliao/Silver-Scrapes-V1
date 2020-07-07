#ifndef _ODOM_HPP_
#define _ODOM_HPP_

#include "main.h"

extern std::shared_ptr<Odometry> odom;

double wrap(double);
QAngle wrap(QAngle);

#endif
