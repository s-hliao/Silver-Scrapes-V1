#include "GUI.hpp"
#include "enums.h"

Side autoSide;
Mode autoMode;

void auto_create(lv_obj_t * parent)
{
  autoSide = LEFT;
  autoMode = CARRY;

  // Create buttons
  btn1 = lv_btn_create(parent, NULL);
  lv_btn_set_fit(btn1, true, true);
  lv_obj_set_pos(btn1, 10, 10);
  lv_btn_set_toggle(btn1, true);
  lv_btn_set_state(btn1, true);
  lv_btn_set_action(btn1, LV_BTN_ACTION_CLICK, left_click);

  btn2 = lv_btn_create(parent, NULL);
  lv_btn_set_fit(btn2, true, true);
  lv_obj_align(btn2, btn1, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
  lv_btn_set_toggle(btn2, true);
  lv_btn_set_action(btn2, LV_BTN_ACTION_CLICK, right_click);

  /*Add labels to the buttons*/
  lv_obj_t * label1 = lv_label_create(btn1, NULL);
  lv_label_set_text(label1, "Left");

  lv_obj_t * label2 = lv_label_create(btn2, NULL);
  lv_label_set_text(label2, "Right");

  // Create button matrix
  static const char * btnm_map[] = {"CARRY", "\n",
                                    "Mid", "\n",
                                    "Short", ""};

  lv_obj_t * btnm1 = lv_btnm_create(parent, NULL);
  lv_btnm_set_map(btnm1, btnm_map);
  lv_obj_set_size(btnm1, 240, 135);
  lv_obj_align(btnm1, btn1, LV_ALIGN_OUT_RIGHT_TOP, 30, 0);
  lv_btnm_set_toggle(btnm1, true, 0);
  lv_btnm_set_action(btnm1, btnm_action);
}

static lv_res_t left_click(lv_obj_t * btn){
  autoSide = LEFT;
  if (lv_btn_get_state(btn1) == true)
    lv_btn_set_state(btn1, true);
  else
    lv_btn_set_state(btn2, false);

  return LV_RES_OK;
}

static lv_res_t right_click(lv_obj_t * btn){
  autoSide = RIGHT;
  if (lv_btn_get_state(btn2) == true)
    lv_btn_set_state(btn2, true);
  else
    lv_btn_set_state(btn1, false);

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
