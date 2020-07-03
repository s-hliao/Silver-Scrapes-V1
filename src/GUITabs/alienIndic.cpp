#include "GUI.hpp"


void alienInit(){
  lv_style_copy(&def, &lv_style_plain);
  def.body.opa = LV_OPA_COVER;
  def.glass = 0;

  def.body.empty = 0;
  def.body.main_color = LV_COLOR_HEX3(0x222);
  def.body.grad_color = LV_COLOR_HEX3(0x222);
  def.body.radius = 0;
  def.body.padding.hor = LV_DPI / 8;
  def.body.padding.ver = LV_DPI / 8;
  def.body.padding.inner = LV_DPI / 8;
  def.body.border.color = LV_COLOR_SILVER;
  def.body.border.width = 1;
  def.body.border.opa = LV_OPA_COVER;
  def.body.shadow.color = LV_COLOR_SILVER;
  def.body.shadow.width = 0;
  def.body.shadow.type = LV_SHADOW_FULL;

  def.text.color = LV_COLOR_HEX3(0xDDD);
  def.text.font = &lv_font_dejavu_10;
  def.text.letter_space = 1;
  def.text.line_space = 2;

  def.image.color = LV_COLOR_HEX3(0xDDD);
  def.image.intense = LV_OPA_TRANSP;

  def.line.color = LV_COLOR_HEX3(0xDDD);
  def.line.width = 1;

lv_style_copy(&tab_indic, &def);
  tab_indic.body.border.width = 0;
  tab_indic.body.main_color = lv_color_hsv_to_rgb(180, 80, 87);
  tab_indic.body.grad_color = lv_color_hsv_to_rgb(180, 80, 87);
  tab_indic.body.padding.inner = 5;
}
