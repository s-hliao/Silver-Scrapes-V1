#include "GUI.hpp"

void pid_create(lv_obj_t * parent)
{

  static lv_style_t style;
  lv_style_copy(&style, lv_page_get_style(parent, LV_PAGE_STYLE_BG));
  style.body.padding.hor = 10;
  style.body.padding.ver = 0;
  lv_page_set_style(parent, LV_PAGE_STYLE_BG, &style);
  lv_page_set_sb_mode(parent, LV_SB_MODE_OFF);

  // PID TEXT
  static lv_obj_t * p = lv_label_create(parent, NULL);
  lv_label_set_text(p, "P");
  lv_obj_align(p, NULL, LV_ALIGN_IN_TOP_LEFT, 55, 0);
  static lv_obj_t * i = lv_label_create(parent, NULL);
  lv_label_set_text(i, "I");
  lv_obj_align(i, p, LV_ALIGN_OUT_RIGHT_TOP, 85, 0);
  static lv_obj_t * d = lv_label_create(parent, NULL);
  lv_label_set_text(d, "D");
  lv_obj_align(d, i, LV_ALIGN_OUT_RIGHT_TOP, 85, 0);

  // Distance container
  static lv_obj_t * box1;
  box1 = lv_cont_create(parent, NULL);
  lv_obj_set_pos(box1, 0, 45);
  lv_obj_set_size(box1, 300, 75);
  static lv_obj_t * txt1 = lv_label_create(box1, NULL);
  lv_label_set_text(txt1, "Distance");
  lv_obj_align(txt1, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 5);

  // Distance buttons
  static lv_obj_t * dpb = lv_btn_create(box1, NULL);
  lv_obj_set_size(dpb, 80, 40);
  lv_obj_align(dpb, NULL, LV_ALIGN_IN_TOP_LEFT, 20, 30);
  static lv_obj_t * dpt = lv_label_create(dpb, NULL);
  lv_label_set_text(dpt, "0");

  static lv_obj_t * dib = lv_btn_create(box1, NULL);
  lv_obj_set_size(dib, 80, 40);
  lv_obj_align(dib, dpb, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
  static lv_obj_t * dit = lv_label_create(dib, NULL);
  lv_label_set_text(dit, "0");

  static lv_obj_t * ddb = lv_btn_create(box1, NULL);
  lv_obj_set_size(ddb, 80, 40);
  lv_obj_align(ddb, dib, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
  static lv_obj_t * ddt = lv_label_create(ddb, NULL);
  lv_label_set_text(ddt, "0");

  // Heading container
  static lv_obj_t * box2;
  box2 = lv_cont_create(parent, NULL);
  lv_obj_set_size(box2, 300, 75);
  lv_obj_align(box2, box1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
  static lv_obj_t * txt2 = lv_label_create(box2, NULL);
  lv_label_set_text(txt2, "Heading");
  lv_obj_align(txt2, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 5);

  // Heading buttons
  static lv_obj_t * hpb = lv_btn_create(box2, NULL);
  lv_obj_set_size(hpb, 80, 40);
  lv_obj_align(hpb, NULL, LV_ALIGN_IN_TOP_LEFT, 20, 30);
  static lv_obj_t * hpt = lv_label_create(hpb, NULL);
  lv_label_set_text(hpt, "0");

  static lv_obj_t * hib = lv_btn_create(box2, NULL);
  lv_obj_set_size(hib, 80, 40);
  lv_obj_align(hib, hpb, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
  static lv_obj_t * hit = lv_label_create(hib, NULL);
  lv_label_set_text(hit, "0");

  static lv_obj_t * hdb = lv_btn_create(box2, NULL);
  lv_obj_set_size(hdb, 80, 40);
  lv_obj_align(hdb, hib, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
  static lv_obj_t * hdt = lv_label_create(hdb, NULL);
  lv_label_set_text(hdt, "0");

  // Plus minus buttons
  static lv_obj_t * btnP = lv_btn_create(parent, NULL);
  lv_obj_set_size(btnP, 80, 50);
  lv_obj_align(btnP, box1, LV_ALIGN_OUT_RIGHT_TOP, 45, -20);
  static lv_obj_t * txt3 = lv_label_create(btnP, NULL);
  lv_label_set_text(txt3, "+");

  static lv_obj_t * btnM = lv_btn_create(parent, NULL);
  lv_obj_set_size(btnM, 80, 50);
  lv_obj_align(btnM, btnP, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
  static lv_obj_t * txt4 = lv_label_create(btnM, NULL);
  lv_label_set_text(txt4, "-");

  // Multiplyer button
  static lv_obj_t * multb = lv_btn_create(parent, NULL);
  lv_obj_set_size(multb, 80, 40);
  lv_obj_align(multb, btnM, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
  static lv_obj_t * txt5 = lv_label_create(multb, NULL);
  lv_label_set_text(txt5, "x1");
}
