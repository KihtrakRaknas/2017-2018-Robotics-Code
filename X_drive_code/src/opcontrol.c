#include "main.h"
#include "global.h"

#define sinyay .7071067812 //This is the sine and cosine of 45

long double siner (long double); //Takes in an angle amd returns the sine of that angle
long double cosiner(long double); //Takes in an angle amd returns the cosine of that angle
void driving(); //The function will read the left joystick's coordinates and will set the motor's speeds to match
void turning(); //The function will read the right joystick's X coordinate and will set the motor's speeds to turn the robot at that rate
void armspeed(int); //Takes in the speed the arm needs to move at and moves both motors at that speed
void launch(); //The function will move the arm up and after a delay open the claw, "throwing" what ever was in the claw
void autooc(); //A shortcut to quickly open and close the claw
void forward(); //A set of pre configured motor speeds to drive forward
void backward(); //A set of pre configured motor speeds to drive backward
void right(); //A set of pre configured motor speeds to drive right
void left(); //A set of pre configured motor speeds to drive left
void auton(); //The code we plan to use for our auton
void randomness(); //The Konami Code

int xpos = 0;
int ypos = 0;
int temp = 0;
int angle = 45; //counter clockwise
int turn = 0;
int headless=0;
int x = 0;

void operatorControl() {
  //Code for Gyro:
  /*
  gyroob = NULL;
  gyroob = gyroInit(gyroport, 0);
  */
  while (1) {
    //Base wheels
    if(joystickGetDigital(1,7,JOY_DOWN)){
      headless++;
    }
    if(!(-20>joystickGetAnalog(1,1) || joystickGetAnalog(1,1)>20)){
      //Code for Gyro:
      /*
      if(headless%2==0){
        angle = gyroGet(gyroob);
      }else{
        angle = 45;
      }
      */
      driving();
    }else{
      turning();
    }

    //Arm controls
    if(joystickGetDigital(1,5,JOY_UP)){
      armspeed(85);
    }else if(joystickGetDigital(1,5,JOY_DOWN)){
      armspeed(-42);
    }else if(-20<joystickGetAnalog(1,2) || joystickGetAnalog(1,2)<20){ //The right joystick's Y coordinate can control the arm
      armspeed(joystickGetAnalog(1,2));
    }else{
      armspeed(0);
    }

    //Claw controls
    if(joystickGetDigital(1,6,JOY_UP)){
      motorSet(CLAW,127);
    }else if(joystickGetDigital(1,6,JOY_DOWN)){
      motorSet(CLAW,-127);
    }else{
      motorSet(CLAW,0);
    }

    //Short cut buttons
    if(joystickGetDigital(1,8,JOY_UP)){
      launch(); //Idea to launch items
    }
    if(joystickGetDigital(1,8,JOY_LEFT)||joystickGetDigital(1,8,JOY_RIGHT)){
      autooc(); //Auto open and close claw
    }
    if(joystickGetDigital(1,8,JOY_DOWN)){
      auton(); //test motors
    }
    if(joystickGetDigital(1,7,JOY_UP)){
      randomness();
    }
  }
}


//Functions:


//sin function
long double siner(long double sinn){
    while(sinn>90){
        sinn = 90-(sinn-90);
    }
    sinn= sinn*.0174533;
    return sinn-((sinn*sinn*sinn)/6)+((sinn*sinn*sinn*sinn*sinn)/120)-((sinn*sinn*sinn*sinn*sinn*sinn*sinn)/5040)+((sinn*sinn*sinn*sinn*sinn*sinn*sinn*sinn*sinn)/362880);
}
//cosin function
long double cosiner(long double cosinn){
    int i = 0;
    while(cosinn>90){
        cosinn = (cosinn-90)-90;
        i++;
    }
    cosinn= cosinn*.0174533;
    if (i%2==1){
        return -1*(1-((cosinn*cosinn)/2)+((cosinn*cosinn*cosinn*cosinn)/24)-((cosinn*cosinn*cosinn*cosinn*cosinn*cosinn)/720)+((cosinn*cosinn*cosinn*cosinn*cosinn*cosinn*cosinn*cosinn)/40320));
    }else{
        return 1-((cosinn*cosinn)/2)+((cosinn*cosinn*cosinn*cosinn)/24)-((cosinn*cosinn*cosinn*cosinn*cosinn*cosinn)/720)+((cosinn*cosinn*cosinn*cosinn*cosinn*cosinn*cosinn*cosinn)/40320);
    }
}

//run motors based on the direction of the joystick
void driving(){
  //Get the X and Y coordinates from the controller
  xpos = joystickGetAnalog(1, 4);
  ypos = joystickGetAnalog(1, 3);
  temp = xpos;
  //Use a rotation matrix to get new coordinates
  xpos = ((cosiner(angle) * xpos) - (siner(angle) * ypos));
  ypos = ((siner(angle) * temp) + (cosiner(angle) * ypos));

  if(ypos >85 && xpos>85){
      ypos = 127;
      xpos = 127;
  }else if(ypos >85 && xpos<-85){
    ypos = 127;
    xpos = -127;
  }else if(ypos <-85 && xpos<-85){
    ypos = -127;
    xpos = -127;
  }else if(ypos <-85 && xpos>85){
    ypos = -127;
    xpos = 127;
  }else if((-10<xpos && xpos<10)&&(-10<ypos && ypos<10)){
    ypos = 0;
    xpos = 0;
  }

  //powers motors at calculated speeds
  motorSet(TR,  xpos);
  motorSet(TL,  ypos);
  motorSet(BL, -1 * xpos);
  motorSet(BR, -1 * ypos);
}

//run motors to turn at the right rate
void turning(){
  turn = joystickGetAnalog(1,1);
  //all the motors turn at the speed given by the joystick
  motorSet(TL, turn);
  motorSet(BR, turn);
  motorSet(TR, turn);
  motorSet(BL, turn);
}

//One motor is pluged in backwards
void armspeed(int speed){
  motorSet(ARM, speed);
  motorSet(ARMT, speed);
}

void launch(){
  motorSet(ARM,127);
  delay(500);
  motorSet(CLAW,127);
  delay(500);
  motorStop(CLAW);
}

void autooc(){
  if(x%2==0){
    motorSet(CLAW, 127);
    delay(2200);
    motorStop(CLAW);
  }else{
    motorSet(CLAW, -127);
    delay(2200);
    motorStop(CLAW);
  }
  x++;
}

void forward(){
  motorSet(TL, 127);
  motorSet(BR, -127);
  motorSet(TR, -127);
  motorSet(BL, 127);
}
void backward(){
  motorSet(TL, -127);
  motorSet(BR, 127);
  motorSet(TR, 127);
  motorSet(BL, -127);
}
void right(){
  motorSet(TL, 127);
  motorSet(BR, -127);
  motorSet(TR, 127);
  motorSet(BL, -127);
}
void left(){
  motorSet(TL, -127);
  motorSet(BR, 127);
  motorSet(TR, -127);
  motorSet(BL, 127);
}

void auton(){
  forward();
  delay(1750);
  motorSet(TL, 0);
  motorSet(BR, 0);
  motorSet(TR, 0);
  motorSet(BL, 0);
  armspeed(127);
  delay(1450);
  armspeed(0);
  forward();
  delay(300);
  motorSet(TL, 0);
  motorSet(BR, 0);
  motorSet(TR, 0);
  motorSet(BL, 0);
  motorSet(CLAW, 127);
  delay(1500);
  motorSet(CLAW, 0);
  /*
  forward();
  backward();
  right();
  left();
  forward();
  delay(500);
  backward();
  delay(500);
  right();
  delay(500);
  left();
  delay(500);
  forward();
  delay(1000);
  backward();
  delay(1000);
  right();
  delay(1000);
  left();
  delay(1000);
  motorSet(TL, 127);
  motorSet(BR, 127);
  motorSet(TR, 127);
  motorSet(BL, 127);
  delay(10000);
  */
}

void randomness(){
  motorSet(TL, 127);
  motorSet(BR, 127);
  motorSet(TR, 127);
  motorSet(BL, 127);
  delay(1000);
  if(joystickGetDigital(1,7,JOY_UP)){
      motorSet(TL, -127);
      motorSet(BR, -127);
      motorSet(TR, -127);
      motorSet(BL, -127);
      delay(1000);
      if(joystickGetDigital(1,7,JOY_DOWN)){
          motorSet(TL, 127);
          motorSet(BR, 127);
          motorSet(TR, 127);
          motorSet(BL, 127);
          delay(1000);
          if(joystickGetDigital(1,7,JOY_DOWN)){
              motorSet(TL, -127);
              motorSet(BR, -127);
              motorSet(TR, -127);
              motorSet(BL, -127);
              delay(1000);
              if(joystickGetDigital(1,7,JOY_LEFT)){
                  motorSet(TL, 127);
                  motorSet(BR, 127);
                  motorSet(TR, 127);
                  motorSet(BL, 127);
                  delay(1000);
                  if(joystickGetDigital(1,7,JOY_RIGHT)){
                      motorSet(TL, -127);
                      motorSet(BR, -127);
                      motorSet(TR, -127);
                      motorSet(BL, -127);
                      delay(1000);
                      if(joystickGetDigital(1,7,JOY_LEFT)){
                          motorSet(TL, 127);
                          motorSet(BR, 127);
                          motorSet(TR, 127);
                          motorSet(BL, 127);
                          delay(1000);
                          if(joystickGetDigital(1,7,JOY_RIGHT)){
                              motorSet(TL, -127);
                              motorSet(BR, -127);
                              motorSet(TR, -127);
                              motorSet(BL, -127);
                              delay(1000);
                              //TESTING MOTORS
                              while(1==1){
                                  motorSet(TL, 127);
                                  motorSet(BR, 127);
                                  motorSet(TR, 127);
                                  motorSet(BL, 127);
                                  delay(15000);
                                  motorSet(TL, -127);
                                  motorSet(BR, -127);
                                  motorSet(TR, -127);
                                  motorSet(BL, -127);
                                  delay(5000);
                                  forward();
                                  delay(5000);
                                  right();
                                  backward();
                                  delay(5000);
                                  left();
                                  delay(5000);
                                  forward();
                                  delay(5000);
                                  backward();
                                  delay(5000);
                                  forward();
                                  delay(5000);
                                  backward();
                                  delay(5000);
                                  forward();
                                  delay(5000);
                                  backward();
                                  delay(5000);
                                  left();
                                  delay(5000);
                                  right();
                                  delay(5000);
                                  left();
                                  delay(5000);
                                  right();
                                  delay(5000);
                              }
                          }
                      }
                  }
              }
          }
      }
  }
}
