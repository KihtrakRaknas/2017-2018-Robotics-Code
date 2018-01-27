
#include "main.h"
#include "global.h"

void stopDriving(){
    motorSet(BL, 0);
    motorSet(TL, 0);
    motorSet(TR, 0);
    motorSet(BR, 0);
    motorSet(CLAWL, 0);
}
void forward(){
  motorSet(TL, 100);
  motorSet(BL, 100);
  motorSet(TR, -100);
  motorSet(BR, -100);
}
void backward(){
  motorSet(TL, -127);
  motorSet(BL, -127);
  motorSet(TR, 127);
  motorSet(BR, 127);
}
void right(){
  motorSet(TL, 127);
  motorSet(BL, 127);
  motorSet(TR, 127);
  motorSet(BR, 127);
}
void left(){
  motorSet(TL, -127);
  motorSet(BL, -127);
  motorSet(TR, -127);
  motorSet(BR, -127);
}
void autonomous() {
  motorSet(MGR, 127);
  delay(800);
  motorStop(MGR);
  motorSet(TL, 20);
  motorSet(ML, 20);
  motorSet(BL, 20);
  motorSet(TR, -20);
  motorSet(MR, -20);
  motorSet(BR, -20);
  delay(7000);
  motorSet(TL, 50);
  motorSet(ML, 50);
  motorSet(BL, 50);
  motorSet(TR, 50);
  motorSet(MR, 50);
  motorSet(BR, 50);
  delay(1390);
  motorSet(TL, 20);
  motorSet(ML, 20);
  motorSet(BL, 20);
  motorSet(TR, -20);
  motorSet(MR, -20);
  motorSet(BR, -20);
  delay(8000);
  motorSet(TL, 127);
  motorSet(ML, 127);
  motorSet(BL, 127);
  motorSet(TR, -127);
  motorSet(MR, -127);
  motorSet(BR, -127);
  delay(300);
  motorStopAll();
  motorSet(MGR, -127);
  delay(800);
  motorSet(TL, -50);
  motorSet(ML, -50);
  motorSet(BL, -50);
  motorSet(TR, 50);
  motorSet(MR, 50);
  motorSet(BR, 50);
  delay(1000);
}
