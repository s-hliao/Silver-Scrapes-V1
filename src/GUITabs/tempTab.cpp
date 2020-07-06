#include "GUI.hpp"

lv_obj_t * tempLabels[8];
std::string motorNames[] = {"LFDrive", "LBDrive", "RFDrive", "RBDrive",
"LIntake", "RIntake", "Flywheel", "Roller"};

static lv_style_t reg_style;
static lv_style_t yellow_style;
static lv_style_t red_style;

void tempStylesInit(){
  lv_style_copy(&reg_style, lv_label_get_style(tempLabels[0]));
  lv_style_copy(&yellow_style, &reg_style);
  yellow_style.body.main_color = LV_COLOR_HEX(0xffff00);
  yellow_style.body.grad_color = LV_COLOR_HEX(0xffff00);
  yellow_style.text.color = LV_COLOR_HEX3(0x333);

  lv_style_copy(&red_style, &yellow_style);
  red_style.body.main_color = LV_COLOR_HEX(0xde1738);
  red_style.body.grad_color = LV_COLOR_HEX(0xde1738);
  red_style.text.color = LV_COLOR_HEX3(0x333);
}

 void temp_create(lv_obj_t * parent)
{
  tempLabels[0] = lv_label_create(parent, NULL);
  tempLabels[1] = lv_label_create(parent, NULL);
  tempLabels[2] = lv_label_create(parent, NULL);
  tempLabels[3] = lv_label_create(parent, NULL);
  tempLabels[4] = lv_label_create(parent, NULL);
  tempLabels[5] = lv_label_create(parent, NULL);
  tempLabels[6] = lv_label_create(parent, NULL);
  tempLabels[7] = lv_label_create(parent, NULL);

  tempStylesInit();

  for(int i = 0;i<8; i++){
    lv_label_set_body_draw(tempLabels[i], true);
    lv_label_set_long_mode(tempLabels[i], LV_LABEL_LONG_DOT);
    lv_obj_set_width(tempLabels[i], lv_obj_get_width(parent)/2);
    lv_obj_set_height(tempLabels[i], lv_obj_get_height(parent)/8);
    if(i%2==0){
      lv_obj_set_pos(tempLabels[i], 10, 10+ (i/2)*45);
    } else{
      lv_obj_set_pos(tempLabels[i], 250, 10+ (i/2)*45);
    }
  }

}


void tempUpdate(){
  for(int i = 0; i<8; i++){
    double temp = infinity();
    switch(i){
      case 0:
        temp = LFDrive.getTemperature();
        break;
      case 1:
        temp = LBDrive.getTemperature();
        break;
      case 2:
        temp = RFDrive.getTemperature();
        break;
      case 3:
        temp = RBDrive.getTemperature();
        break;
      case 4:
        temp = LIntake.getTemperature();
        break;
      case 5:
        temp = RIntake.getTemperature();
        break;
      case 6:
        temp = flywheel.getTemperature();
        break;
      case 7:
        temp = roller.getTemperature();
        break;
      default:
        break;
    }

    if(temp!=PROS_ERR_F){

      std::string str = motorNames[i]+": "+std::to_string(lround(temp))+" C";

      lv_label_set_text(tempLabels[i], str.c_str());

      if(temp>=60){
        lv_label_set_style(tempLabels[i], &red_style);
      } else if(temp>=50){
        lv_label_set_style(tempLabels[i], &yellow_style);
      } else{
        lv_label_set_style(tempLabels[i], &reg_style);
      }

    } else{
      std::string str  = motorNames[i]+": No Motor";
      lv_label_set_text(tempLabels[i], str.c_str());
      lv_label_set_style(tempLabels[i], &reg_style);
    }
  }
}
