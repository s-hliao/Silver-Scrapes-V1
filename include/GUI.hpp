#ifndef _GUI_H_
#define _GUI_H_

#include "main.h"

void GUIcreate(void);

void auto_create(lv_obj_t * parent);
void odom_create(lv_obj_t * parent);
void pid_create(lv_obj_t * parent);
void temp_create(lv_obj_t * parent);
void debug_create(lv_obj_t * parent);

void alienInit();

static lv_obj_t * btn1;
static lv_obj_t * btn2;
static lv_res_t left_click(lv_obj_t * btn);
static lv_res_t right_click(lv_obj_t * btn);


#endif
