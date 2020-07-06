#include "GUI.hpp"
#include "enums.h"

Side autoSide;
Mode autoMode;
bool autoRun;

static lv_obj_t * btn1;
static lv_obj_t * btn2;

void auto_create(lv_obj_t * parent)
{
  autoSide = LEFT;
  autoMode = CARRY;
  autoRun = false;

  // Create buttons
  btn1 = lv_btn_create(parent, NULL);
  lv_btn_set_fit(btn1, true, true);
  lv_obj_set_pos(btn1, 10, 10);
  lv_btn_set_state(btn1, true);
  lv_btn_set_action(btn1, LV_BTN_ACTION_CLICK, left_click);

  btn2 = lv_btn_create(parent, NULL);
  lv_btn_set_fit(btn2, true, true);
  lv_obj_align(btn2, btn1, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
  lv_btn_set_action(btn2, LV_BTN_ACTION_CLICK, right_click);

  /*Add labels to the buttons*/
  static lv_obj_t * label1 = lv_label_create(btn1, NULL);
  lv_label_set_text(label1, "Left");

  static lv_obj_t * label2 = lv_label_create(btn2, NULL);
  lv_label_set_text(label2, "Right");

  // Create button matrix
  static const char * btnm_map[] = {"CARRY", "\n",
                                    "Mid", "\n",
                                    "Short", ""};

  static lv_obj_t * btnm1 = lv_btnm_create(parent, NULL);
  lv_btnm_set_map(btnm1, btnm_map);
  lv_obj_set_size(btnm1, 135, 135);
  lv_obj_align(btnm1, btn1, LV_ALIGN_OUT_RIGHT_TOP, 30, 7);
  lv_btnm_set_toggle(btnm1, true, 0);
  lv_btnm_set_action(btnm1, btnm_action);

  // Run auto checkbox
  static lv_obj_t * cb;
  cb = lv_cb_create(parent, NULL);
  lv_obj_align(cb, btnm1, LV_ALIGN_OUT_RIGHT_MID, 30, 0);
  lv_cb_set_text(cb, "Run Auto");
  lv_cb_set_action(cb, cb_release_action);
}

static lv_res_t left_click(lv_obj_t * btn){
  if (lv_btn_get_state(btn1) == false) {
    autoSide = LEFT;
    lv_btn_set_state(btn1, true);
    lv_btn_set_state(btn2, false);
  }

  return LV_RES_OK;
}

static lv_res_t right_click(lv_obj_t * btn){
    if (lv_btn_get_state(btn2) == false) {
    autoSide = RIGHT;
    lv_btn_set_state(btn2, true);
    lv_btn_set_state(btn1, false);
  }

  return LV_RES_OK;
}

static lv_res_t btnm_action(lv_obj_t * btnm, const char *txt)
{
  if (strcmp(txt, "CARRY") ==0) {
    autoMode = CARRY;
  } else if (strcmp(txt, "Mid") == 0) {
    autoMode = MID;
  } else {
    autoMode = SHORT;
  }

  return LV_RES_OK;
}

static lv_res_t cb_release_action(lv_obj_t * cb) {

  if (lv_cb_is_checked(cb) == true) {
    lv_cb_set_text(cb, "Press <A>");
    autoRun = true;
  } else {
    lv_cb_set_text(cb, "Run Auto");
    autoRun = false;
  }

  return LV_RES_OK;
}
