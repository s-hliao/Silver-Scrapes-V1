#ifndef _ENUMS_H_
#define _ENUMS_H_

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


#endif
