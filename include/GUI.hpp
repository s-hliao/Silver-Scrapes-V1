#ifndef _GUI_H_
#define _GUI_H_

#include "main.h"

void GUIcreate(void);
void GUIupdate(void*params);

void auto_create(lv_obj_t * parent);
void odom_create(lv_obj_t * parent);
void pid_create(lv_obj_t * parent);
void temp_create(lv_obj_t * parent);
void debug_create(lv_obj_t * parent);

void odomUpdate();
void tempUpdate();

void alienInit();

static lv_res_t left_click(lv_obj_t * btn);
static lv_res_t right_click(lv_obj_t * btn);
static lv_res_t btnm_action(lv_obj_t * btnm, const char *txt);
static lv_res_t cb_release_action(lv_obj_t * cb);

#endif
