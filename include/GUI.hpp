#ifndef _GUI_H_
#define _GUI_H_

#include "main.h"

void GUIcreate(void);
static void auto_create(lv_obj_t * parent);
static void odom_create(lv_obj_t * parent);
static void pid_create(lv_obj_t * parent);
static void temp_create(lv_obj_t * parent);
static void debug_create(lv_obj_t * parent);

static void alienInit();

static lv_style_t def;
static lv_style_t tab_indic;




#endif
