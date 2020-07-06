#include "main.h"

auto drive = ChassisControllerBuilder()
    .withMotors({LFDrive, LBDrive}, {RFDrive, RBDrive}) // left motor is 1, right motor is 2 (reversed)
    // green gearset, 4 inch wheel diameter geared up, 11.5 inch wheelbase
    .withDimensions(AbstractMotor::gearset::green, {{5.6_in, 11.5_in}, imev5GreenTPR})
    .withSensors(
        ADIEncoder{LQUAD1, LQUAD2}, // left encoder in ADI ports A & B
        ADIEncoder{RQUAD1, RQUAD2, true},  // right encoder in ADI ports C & D (reversed)
        ADIEncoder{MQUAD1, MQUAD2}  // middle encoder in ADI ports E & F
    )
    // specify the tracking wheels diameter (2.75 in), track (7 in), and TPR (360)
    // specify the middle encoder distance (1 in) and diameter (2.75 in)
    .withOdometry({{2.75_in, 7_in, 1_in, 2.75_in}, quadEncoderTPR})
    .buildOdometry();

std::shared_ptr<Odometry> odom = drive->getOdometry();

double wrap(double d){
  double wrapped =d;
  if(d>=360){
    while(wrapped>=360){
      wrapped-=360;
    }
  } else if(d<0){
    while(wrapped<0){
      wrapped+=360;
    }
  }
  return wrapped;
}

QAngle wrap(QAngle d){

  QAngle wrapped =d;
  if(d>=360_deg){
    while(wrapped>=360_deg){
      wrapped-=360_deg;
    }
  } else if(d<0_deg){
    while(wrapped<0_deg){
      wrapped+=360_deg;
    }
  }
  return wrapped;

}
