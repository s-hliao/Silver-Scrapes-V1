#include "GUI.hpp"

void pid_create(lv_obj_t * parent)
{

  static lv_style_t style;
  lv_style_copy(&style, lv_page_get_style(parent, LV_PAGE_STYLE_BG));
  style.body.padding.hor = 10;
  style.body.padding.ver = 0;
  lv_page_set_style(parent, LV_PAGE_STYLE_BG, &style);

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
  static lv_obj_t * dp = lv_btn_create(box1, NULL);
  lv_obj_set_size(dp, 80, 40);
  lv_obj_align(dp, NULL, LV_ALIGN_IN_TOP_LEFT, 20, 30);
  static lv_obj_t * dpt = lv_label_create(dp, NULL);
  lv_label_set_text(dpt, "0");

  static lv_obj_t * di = lv_btn_create(box1, NULL);
  lv_obj_set_size(di, 80, 40);
  lv_obj_align(di, dp, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
  static lv_obj_t * dit = lv_label_create(di, NULL);
  lv_label_set_text(dit, "0");

  static lv_obj_t * dd = lv_btn_create(box1, NULL);
  lv_obj_set_size(dd, 80, 40);
  lv_obj_align(dd, di, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
  static lv_obj_t * ddt = lv_label_create(dd, NULL);
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
  static lv_obj_t * hp = lv_btn_create(box2, NULL);
  lv_obj_set_size(hp, 80, 40);
  lv_obj_align(hp, NULL, LV_ALIGN_IN_TOP_LEFT, 20, 30);
  static lv_obj_t * hpt = lv_label_create(hp, NULL);
  lv_label_set_text(hpt, "0");

  static lv_obj_t * hi = lv_btn_create(box2, NULL);
  lv_obj_set_size(hi, 80, 40);
  lv_obj_align(hi, hp, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
  static lv_obj_t * hit = lv_label_create(hi, NULL);
  lv_label_set_text(hit, "0");

  static lv_obj_t * hd = lv_btn_create(box2, NULL);
  lv_obj_set_size(hd, 80, 40);
  lv_obj_align(hd, hi, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
  static lv_obj_t * hdt = lv_label_create(hd, NULL);
  lv_label_set_text(hdt, "0");

}
