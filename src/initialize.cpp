#include "GUI.hpp"
void initialize(){
  GUIcreate();
  pros::Task GUITask(GUIupdate, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "GUI Update");
}

void competition_initialize() {
}

void disable(){

}
