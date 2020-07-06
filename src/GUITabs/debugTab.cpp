#include "GUI.hpp"

static lv_obj_t * ta1;

void debug_create(lv_obj_t * parent)
{

  // Remove page padding
  static lv_style_t style;
  lv_style_copy(&style, lv_page_get_style(parent, LV_PAGE_STYLE_BG));
  style.body.padding.hor = 0;
  style.body.padding.ver = 0;
  lv_page_set_style(parent, LV_PAGE_STYLE_BG, &style);
  lv_page_set_sb_mode(parent, LV_SB_MODE_OFF);

  // Create text area
  ta1 = lv_ta_create(parent, NULL);
  lv_obj_set_size(ta1, 480, 200);
  lv_obj_align(ta1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

  // Style text area
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
