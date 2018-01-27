
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
forward();
delay(800);
right();
delay(800);
forward();
delay(1000);
motorSet(CLAWL, 70);
motorSet(CLAWR, -70);
delay(200);
left();
delay(500);
forward();
delay(4000);
stopDriving();
}
