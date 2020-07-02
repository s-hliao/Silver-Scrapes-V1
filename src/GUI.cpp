#include "GUI.hpp"


void GUIcreate(void){

  th = lv_theme_mono_init(12, NULL);

    lv_theme_set_current(lv_theme_get_mono()); //when removed Spinbox works fine
    tv = lv_tabview_create(lv_scr_act(), NULL);



    // Tabs
    t1 = lv_tabview_add_tab(tv, "Auto Select");
    t2 = lv_tabview_add_tab(tv, "Odometry");
    t3 = lv_tabview_add_tab(tv, "PID Tuner");
    t4 = lv_tabview_add_tab(tv, "Temperature");
    t5 = lv_tabview_add_tab(tv, "Debug");

/*    lv_style_init(&style_box);
    lv_style_set_value_align(&style_box, LV_STATE_DEFAULT, LV_ALIGN_OUT_TOP_LEFT);
    lv_style_set_value_ofs_y(&style_box, LV_STATE_DEFAULT, - LV_DPX(10));
    lv_style_set_margin_top(&style_box, LV_STATE_DEFAULT, LV_DPX(30));

    // Create tabs
    auto_create(t1);
    odom_create(t2);
    pid_create(t3);
    temp_create(t4);
    debug_create(t5);*/
}
