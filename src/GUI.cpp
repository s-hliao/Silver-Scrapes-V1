#include "GUI.hpp"


void GUIcreate(void){

    th = lv_theme_alien_init(180, NULL);

    lv_theme_set_current(th);
    tv = lv_tabview_create(lv_scr_act(), NULL);

    // Tabs
    t1 = lv_tabview_add_tab(tv, "Auto ");
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

static void auto_create(lv_obj_t * parent)
{
  lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY);

  lv_obj_t * btn = lv_btn_create(parent, NULL);
  lv_btn_set_fit(btn, true, true);
  //lv_obj_set_width(btn, 0);
  lv_obj_t * label = lv_label_create(btn, NULL);
  lv_label_set_text(label ,"Button");

}

static void odom_create(lv_obj_t * parent)
{
  lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY);
}

static void pid_create(lv_obj_t * parent)
{
  lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY);
}

static void temp_create(lv_obj_t * parent)
{
  lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY);
}

static void debug_create(lv_obj_t * parent)
{
  lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY);
}
