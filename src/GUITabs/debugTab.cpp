#include "GUI.hpp"

lv_obj_t * ta1;

void debug_create(lv_obj_t * parent)
{
  ta1 = lv_ta_create(parent, NULL);
  lv_obj_set_size(ta1, 460, 200);
  lv_obj_align(ta1, NULL, LV_ALIGN_CENTER, 0, -20);

  static lv_style_t style_bg;
  lv_style_copy(&style_bg, &lv_style_plain);
  style_bg.body.main_color = LV_COLOR_HEX3(0x333);
  style_bg.body.grad_color = LV_COLOR_HEX3(0x333);
  style_bg.text.color = lv_color_hsv_to_rgb(180, 10, 94);
  lv_ta_set_style(ta1, LV_TA_STYLE_BG, &style_bg);

  lv_ta_set_cursor_type(ta1, LV_CURSOR_BLOCK);

  lv_ta_set_text(ta1, "");
}

void printDebug(const char* txt) {
  lv_ta_add_text(ta1, txt);
}

void printLnDebug(const char* txt) {
  lv_ta_add_text(ta1, txt);
  lv_ta_add_text(ta1, "\n");
}
