#include "GUI.hpp"

static lv_obj_t * tv;
static lv_obj_t * t1;
static lv_obj_t * t2;
static lv_obj_t * t3;
static lv_obj_t * t4;
static lv_obj_t * t5;

static lv_theme_t * th;

static lv_style_t def;
static lv_style_t tab_indic;

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

void GUIcreate(void){
    alienInit();

    // Set theme
    th = lv_theme_alien_init(180, NULL);
    lv_theme_set_current(th);

    // Create tab view
    tv = lv_tabview_create(lv_scr_act(), NULL);

    static lv_style_t tab_style;
    lv_style_copy(&tab_style, lv_tabview_get_style(tv, LV_TABVIEW_STYLE_BTN_REL));
    tab_style.body.padding.ver = 10;

    lv_tabview_set_style(tv, LV_TABVIEW_STYLE_INDIC, &tab_indic);
    lv_tabview_set_style(tv, LV_TABVIEW_STYLE_BTN_REL, &tab_style);

    lv_tabview_set_sliding(tv, false);

    // Add tabs
    t1 = lv_tabview_add_tab(tv, "Auto");
    t2 = lv_tabview_add_tab(tv, "Odom");
    t3 = lv_tabview_add_tab(tv, "PID");
    t4 = lv_tabview_add_tab(tv, "Temp");
    t5 = lv_tabview_add_tab(tv, "Debug");

    // Create tabs
    auto_create(t1);
    odom_create(t2);
    pid_create(t3);
    temp_create(t4);
    debug_create(t5);
}

void GUIupdate(void*params){
  while(true){
    printDebug(SideText[autoSide]);
    printDebug(" ");
    printLnDebug(ModeText[autoMode]);

    pros::Task::delay(2000);
  }

}
