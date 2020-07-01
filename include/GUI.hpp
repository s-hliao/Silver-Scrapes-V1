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

};
