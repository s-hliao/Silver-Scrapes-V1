#ifndef _GUI_H_
#define _GUI_H_

#include "main.h"

void GUIcreate(void);

static lv_obj_t * tv;
static lv_obj_t * t1;
static lv_obj_t * t2;
static lv_obj_t * t3;
static lv_obj_t * t4;
static lv_obj_t * t5;

static lv_theme_t * th;

static void auto_create(lv_obj_t * parent);
static void odom_create(lv_obj_t * parent);
static void pid_create(lv_obj_t * parent);
static void temp_create(lv_obj_t * parent);
static void debug_create(lv_obj_t * parent);

#endif
