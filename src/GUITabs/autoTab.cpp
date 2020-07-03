#include "GUI.hpp"

void auto_create(lv_obj_t * parent)
{

  // Create buttons
  lv_obj_t * btn1 = lv_btn_create(parent, NULL);
  lv_btn_set_fit(btn1, true, true);
  lv_obj_set_pos(btn1, 10, 10);
  lv_btn_set_toggle(btn1, true);

  lv_obj_t * btn2 = lv_btn_create(parent, NULL);
  lv_btn_set_fit(btn2, true, true);
  lv_obj_align(btn2, btn1, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
  lv_btn_set_toggle(btn2, false);

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
  lv_obj_align(btnm1, btn1, LV_ALIGN_OUT_RIGHT_BOTTOM, 30, 0);

}
