#ifndef _ENUMS_HPP_
#define _ENUMS_HPP_

enum Side : int {
  LEFT,
  RIGHT
};

static const char * SideText[] =
{
    "LEFT",
    "RIGHT"
};

enum Mode : int {
  CARRY,
  MID,
  SHORT
};

static const char * ModeText[] =
{
    "CARRY",
    "MID",
    "SHORT"
};

enum PID : int {
  DP,
  DI,
  DD,
  HP,
  HI,
  HD,
  MULT
};

#endif
