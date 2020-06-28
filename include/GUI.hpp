#pragma once
#include "main.h"

class GUI{
  public:
    struct state_t {
      QLength x {0.0};
      QLength y {0.0};
      QAngle theta {0.0};

      state_t(QLength ix, QLength iy, QAngle itheta);
    };

    struct sensors_t {
      double left {0.0};
      double right {0.0};
      double middle {0.0};

      sensors_t(double ileft, double iright);

      sensors_t(double ileft, double iright, double imiddle);

      private:
        bool hasMiddle {false};
        friend class OdomDebug;
    };

  GUI(lv_obj_t* parent);
  ~GUI();

  void setStateCallback(std::function<void(state_t state)> callback);

  void setResetCallback(std::function<void()> callback);

  void setData(state_t state, sensors_t sensors);

  private:
    lv_obj_t *tabview = nullptr;

    lv_obj_t *tabTemps = nullptr;
    lv_obj_t *tabAuto = nullptr;
    lv_obj_t *tabOdom = nullptr;

    lv_style_t tabStyle;

//Temps section
  lv_obj_t* motorLabel1 = nullptr;
  lv_obj_t* motorLabel2 = nullptr;
  lv_obj_t* motorLabel3 = nullptr;
  lv_obj_t* motorLabel4 = nullptr;
  lv_obj_t* motorLabel5 = nullptr;
  lv_obj_t* motorLabel6 = nullptr;
  lv_obj_t* motorLabel7 = nullptr;
  lv_obj_t* motorLabel8 = nullptr;

  lv_style_t okStyle;
  lv_style_t deadStyle;

//Auto section

  lv_style_t colorStyle;
  lv_style_t sideStyle;
  lv_style_t dropDownStyle;



// Odom section
    lv_style_t fStyle;
   double fieldDim = 0; // width and height of field container

   // tile styles
   lv_style_t grey;

   // robot point
   lv_obj_t* led = nullptr;
   lv_style_t ledStyle;

   // robot line
   lv_obj_t* line = nullptr;
   lv_style_t lineStyle;
   std::vector<lv_point_t> linePoints = {{0, 0}, {0, 0}}; // line positions
   int lineWidth = 0;
   int lineLength = 0;

   // status label
   lv_obj_t* statusLabel = nullptr;
   lv_style_t textStyle;

   // reset button styles
   lv_style_t resetRel;
   lv_style_t resetPr;

   // external callbacks to interface with odometry
   std::function<void(state_t state)> stateFnc = nullptr;
   std::function<void()> resetFnc = nullptr;

   static lv_res_t resetAction(lv_obj_t*); // action when reset button is pressed

};
