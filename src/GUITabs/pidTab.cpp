#include "GUI.hpp"
#include "pid.h"

static lv_obj_t * dpb;
static lv_obj_t * dib;
static lv_obj_t * ddb;
static lv_obj_t * hpb;
static lv_obj_t * hib;
static lv_obj_t * hdb;
static lv_obj_t * multb;

static lv_obj_t * dpt;
static lv_obj_t * dit;
static lv_obj_t * ddt;
static lv_obj_t * hpt;
static lv_obj_t * hit;
static lv_obj_t * hdt;
static lv_obj_t * multt;

PID selected = DP;

const char* DoubleToString(double value){
    std::stringstream ss;
    ss << value;
    const char* str = ss.str().c_str();
    return str;
}

const char* concat(const char* one, const char* two) {
  char* buf = new char[100];
  strcpy(buf, one);
  strcat(buf, two);
  return buf;
}

static void toggleOff(){
  lv_btn_set_state(dpb, false);
  lv_btn_set_state(dib, false);
  lv_btn_set_state(ddb, false);
  lv_btn_set_state(hpb, false);
  lv_btn_set_state(hib, false);
  lv_btn_set_state(hdb, false);
  lv_btn_set_state(multb, false);
}

static lv_res_t selectDP(lv_obj_t * btn){

  toggleOff();
  lv_btn_set_state(btn, true);
  selected = DP;
  return LV_RES_OK;
}

static lv_res_t selectDI(lv_obj_t * btn){

  toggleOff();
  lv_btn_set_state(btn, true);
  selected = DI;
  return LV_RES_OK;
}

static lv_res_t selectDD(lv_obj_t * btn){

  toggleOff();
  lv_btn_set_state(btn, true);
  selected = DD;
  return LV_RES_OK;
}

static lv_res_t selectHP(lv_obj_t * btn){

  toggleOff();
  lv_btn_set_state(btn, true);
  selected = HP;
  return LV_RES_OK;
}

static lv_res_t selectHI(lv_obj_t * btn){

  toggleOff();
  lv_btn_set_state(btn, true);
  selected = HI;
  return LV_RES_OK;
}

static lv_res_t selectHD(lv_obj_t * btn){

  toggleOff();
  lv_btn_set_state(btn, true);
  selected = HD;
  return LV_RES_OK;
}

static lv_res_t selectMult(lv_obj_t * btn){

  toggleOff();
  lv_btn_set_state(btn, true);
  selected = MULT;
  return LV_RES_OK;
}

static void updateText() {
  lv_label_set_text(dpt, DoubleToString(DkP));
  lv_label_set_text(dit, DoubleToString(DkI));
  lv_label_set_text(ddt, DoubleToString(DkD));
  lv_label_set_text(hpt, DoubleToString(HkP));
  lv_label_set_text(hit, DoubleToString(HkI));
  lv_label_set_text(hdt, DoubleToString(HkD));
  lv_label_set_text(multt, DoubleToString(multiplier));
}

static lv_res_t plus(lv_obj_t * btn){
  switch (selected) {
    case DP:
      DkP += multiplier;
      break;
    case DI:
      DkI += multiplier;
      break;
    case DD:
      DkD += multiplier;
      break;
    case HP:
      HkP += multiplier;
      break;
    case HI:
      HkI += multiplier;
      break;
    case HD:
      HkD += multiplier;
      break;
    case MULT:
      multiplier *= 10;
      break;
  }
  updateText();
  return LV_RES_OK;
}

static lv_res_t minus(lv_obj_t * btn){
  switch (selected) {
    case DP:
      DkP -= multiplier;
      break;
    case DI:
      DkI -= multiplier;
      break;
    case DD:
      DkD -= multiplier;
      break;
    case HP:
      HkP -= multiplier;
      break;
    case HI:
      HkI -= multiplier;
      break;
    case HD:
      HkD -= multiplier;
      break;
    case MULT:
      multiplier /= 10;
      break;
  }
  updateText();
  return LV_RES_OK;
}

void pid_create(lv_obj_t * parent)
{

  // Remove padding
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
  dpb = lv_btn_create(box1, NULL);
  lv_obj_set_size(dpb, 80, 40);
  lv_obj_align(dpb, NULL, LV_ALIGN_IN_TOP_LEFT, 20, 30);
  lv_btn_set_state(dpb, true);
  dpt = lv_label_create(dpb, NULL);

  dib = lv_btn_create(box1, NULL);
  lv_obj_set_size(dib, 80, 40);
  lv_obj_align(dib, dpb, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
  dit = lv_label_create(dib, NULL);
  lv_label_set_text(dit, DoubleToString(DkI));

  ddb = lv_btn_create(box1, NULL);
  lv_obj_set_size(ddb, 80, 40);
  lv_obj_align(ddb, dib, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
  ddt = lv_label_create(ddb, NULL);
  lv_label_set_text(ddt, DoubleToString(DkD));

  // Heading container
  static lv_obj_t * box2;
  box2 = lv_cont_create(parent, NULL);
  lv_obj_set_size(box2, 300, 75);
  lv_obj_align(box2, box1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
  static lv_obj_t * txt2 = lv_label_create(box2, NULL);
  lv_label_set_text(txt2, "Heading");
  lv_obj_align(txt2, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 5);

  // Heading buttons
  hpb = lv_btn_create(box2, NULL);
  lv_obj_set_size(hpb, 80, 40);
  lv_obj_align(hpb, NULL, LV_ALIGN_IN_TOP_LEFT, 20, 30);
  hpt = lv_label_create(hpb, NULL);
  lv_label_set_text(hpt, DoubleToString(HkP));

  hib = lv_btn_create(box2, NULL);
  lv_obj_set_size(hib, 80, 40);
  lv_obj_align(hib, hpb, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
  hit = lv_label_create(hib, NULL);
  lv_label_set_text(hit, DoubleToString(HkI));

  hdb = lv_btn_create(box2, NULL);
  lv_obj_set_size(hdb, 80, 40);
  lv_obj_align(hdb, hib, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
  hdt = lv_label_create(hdb, NULL);
  lv_label_set_text(hdt, DoubleToString(HkD));

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
  multb = lv_btn_create(parent, NULL);
  lv_obj_set_size(multb, 80, 40);
  lv_obj_align(multb, btnM, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
  multt = lv_label_create(multb, NULL);
  printf(concat("x", DoubleToString(multiplier)));
  lv_label_set_text(multt, concat("x", DoubleToString(multiplier)));

  // Button actions
  lv_btn_set_action(dpb, LV_BTN_ACTION_CLICK, selectDP);
  lv_btn_set_action(dib, LV_BTN_ACTION_CLICK, selectDI);
  lv_btn_set_action(ddb, LV_BTN_ACTION_CLICK, selectDD);
  lv_btn_set_action(hpb, LV_BTN_ACTION_CLICK, selectHP);
  lv_btn_set_action(hib, LV_BTN_ACTION_CLICK, selectHI);
  lv_btn_set_action(hdb, LV_BTN_ACTION_CLICK, selectHD);
  lv_btn_set_action(multb, LV_BTN_ACTION_CLICK, selectMult);

  lv_btn_set_action(btnP, LV_BTN_ACTION_CLICK, plus);
  lv_btn_set_action(btnM, LV_BTN_ACTION_CLICK, minus);

  updateText();
}
