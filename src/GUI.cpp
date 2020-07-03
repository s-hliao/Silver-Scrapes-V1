#include "GUI.hpp"


void GUIcreate(void){

    // Set theme
    th = lv_theme_alien_init(180, NULL);
    lv_theme_set_current(th);

    // Create tab view
    tv = lv_tabview_create(lv_scr_act(), NULL);
    static lv_style_t ind_style;
    static lv_style_t tab_style;

/*    lv_style_copy(&ind_style, lv_tabview_get_style(tv, LV_TABVIEW_STYLE_INDIC));
    ind_style.body.padding.ver = 1;*/
    lv_style_copy(&tab_style, &*lv_tabview_get_style(tv, LV_TABVIEW_STYLE_BTN_REL));
    tab_style.body.padding.ver = 10;

  //  lv_tabview_set_style(tv, LV_TABVIEW_STYLE_INDIC, &ind_style);
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

static void auto_create(lv_obj_t * parent)
{

  // Create buttons
  lv_obj_t * btn1 = lv_btn_create(parent, NULL);
  lv_btn_set_fit(btn1, true, true);
  lv_obj_set_pos(btn1, 10, 10);
  lv_btn_set_toggle(btn1, true);

  lv_obj_t * btn2 = lv_btn_create(parent, NULL);
  lv_btn_set_fit(btn1, true, true);
  lv_obj_align(btn2, btn1, LV_ALIGN_OUT_RIGHT_BOTTOM, 0, 0);
  lv_btn_set_toggle(btn1, false);

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
  lv_obj_align(btnm1, btn1, LV_ALIGN_OUT_RIGHT_MID, 30, 0);

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
