#include "GUI.hpp"


void GUIcreate(void){

    // Set theme
    th = lv_theme_alien_init(180, NULL);
    lv_theme_set_current(th);

    // Create tab view
    tv = lv_tabview_create(lv_scr_act(), NULL);

    // Add tabs
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

  th = lv_theme_alien_init(180, NULL);

  // Get the size of the usable screen
  int w = lv_obj_get_width(parent);
  int h = lv_obj_get_height(parent);

  // Create the side container
  lv_obj_t * cont = lv_cont_create(parent, NULL);
  lv_obj_set_size(cont, w/2 - 5, h/2 - 5);
  lv_cont_set_layout(cont, LV_LAYOUT_COL_L);
  lv_obj_align(cont, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

  // Add text and buttons
  lv_obj_t * cont_txt = lv_label_create(cont, NULL);
  lv_label_set_text(cont_txt, "Side");

  lv_obj_t * btn = lv_btn_create(parent, NULL);
  lv_obj_t * label = lv_label_create(btn, NULL);
  lv_label_set_text(label ,"Red");

  btn = lv_btn_create(parent, btn);
  lv_label_set_text(label ,"Blue");

  // Create the mode container
  cont = lv_cont_create(parent, cont);
  lv_obj_set_size(cont, w/2 - 5, h/2 - 5);
  lv_cont_set_layout(cont, LV_LAYOUT_COL_L);
  lv_obj_align(cont, NULL, LV_ALIGN_IN_TOP_RIGHT, 0, 0);

  // Add the roller
  lv_obj_t * roller = lv_roller_create(parent, NULL);
  lv_roller_set_options(roller, "Carry\n"
                               "Left Mid\n"
                               "Right Mid\n"
                               "Left\n"
                               "Right\n");

}

static void odom_create(lv_obj_t * parent)
{

}

static void pid_create(lv_obj_t * parent)
{
  lv_page_set_scrl_layout(parent, LV_LAYOUT_GRID);
}

static void temp_create(lv_obj_t * parent)
{
  lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY);
}

static void debug_create(lv_obj_t * parent)
{
  lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY);
}
