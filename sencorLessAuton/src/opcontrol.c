#include "main.h"
#include "global.h"
int OCcounter = 0;
#define thresh 10
FILE *fptr;
int i = 0;
void rec(int tim , int motor, int speed){
	fprintf(fptr, ",%d,%d,%d ", tim,motor, speed);
}

void mobileGoalSpeed(int speed){//+speed = up
  //motorSet(ARMBL, -1 * speed);
  //motorSet(MGL, -1 * speed);
  //motorSet(ARMBR, speed);
  motorSet(MGR, speed);
	rec(i,MGR,speed);
}

void autooc(){
  if(OCcounter%2==0){
    mobileGoalSpeed(127);
    delay(600);
    mobileGoalSpeed(0);
  }else{
    mobileGoalSpeed(-127);
    delay(600);
    mobileGoalSpeed(0);
  }
  OCcounter++;
}

void driving(){
  //Get the X and Y coordinates from the controller
    int xpos = joystickGetAnalog(1, 1);
    int ypos = joystickGetAnalog(1, 3);

    //powers motors at correct speeds
    if(!(ypos < -thresh || thresh < ypos || xpos < -thresh || thresh < xpos)){
      ypos=0;
      xpos=0;
    }
  if(ypos >= -thresh){
    xpos = xpos * -1;
  }
  motorSet(BL, (ypos-xpos));
  motorSet(ML, (ypos-xpos));
  motorSet(TL, (ypos-xpos));
	rec(i,TL,(ypos-xpos));
  motorSet(TR, -1 * (ypos+xpos));
  motorSet(MR, -1 * (ypos+xpos));
  motorSet(BR, -1 * (ypos+xpos));
	rec(i,TR,-1 * (ypos+xpos));
}

void armspeed(int speed){//+speed = up
  //motorSet(ARMBL, -1 * speed);
  motorSet(ARML, -1 * speed);
  //motorSet(ARMACTUALR, speed);
  motorSet(ARMR, speed);
	rec(i,ARMR,speed);
}

void RIcontrol(int speed){//+speed=close //RI = rakesh intake
  motorSet(CLAWL,speed);
  motorSet(CLAWR,-1 * speed);
	rec(i,CLAWL,speed);
}
void operatorControl() {
	fptr = fopen("auton.txt", "r");
	if (!(fptr == NULL)){
		for(int i = 0; i!=3;i++){
			printf("Printing contents of the file\n\n");
			delay(1000);
		}
		char string[5];
		while(fgets(string, 5,fptr)!=NULL){
			printf("%s", string);
			delay(20);
		}
		fclose(fptr);
		printf("\nDONE!");
	}

	fptr = fopen("auton.txt", "w");
	fprintf(fptr, "{");
	while (1) {
      driving();

      //Arm controls
      if(joystickGetDigital(1,5,JOY_UP)||joystickGetDigital(2,5,JOY_UP)){
        mobileGoalSpeed(-127);
      }else if(joystickGetDigital(1,5,JOY_DOWN)||joystickGetDigital(2,5,JOY_DOWN)){
        mobileGoalSpeed(127);
      }else{
        mobileGoalSpeed(0);
      }

      if(-10<joystickGetAnalog(1,2) || joystickGetAnalog(1,2)<10){ //The right joystick's Y coordinate can control the arm
        armspeed(joystickGetAnalog(1,2));
      }else if(-10<joystickGetAnalog(2,2) || joystickGetAnalog(2,2)<10){ //The right joystick's Y coordinate can control the arm
        armspeed(joystickGetAnalog(2,2));
      }else{
        armspeed(0);
      }

      //Claw controls
      if(joystickGetDigital(1,6,JOY_UP)||joystickGetDigital(2,6,JOY_UP)){
        RIcontrol(70);
      }else if(joystickGetDigital(1,6,JOY_DOWN)||joystickGetDigital(2,6,JOY_DOWN)){
        RIcontrol(-70);
      }else{
        RIcontrol(0);
      }

      if(joystickGetDigital(1,8,JOY_LEFT)||joystickGetDigital(1,8,JOY_RIGHT)||joystickGetDigital(2,8,JOY_LEFT)||joystickGetDigital(2,8,JOY_RIGHT)){
        autooc(); //Auto open and close claw
      }
			i++;
			delay(20);
			if(joystickGetDigital(1,7,JOY_DOWN)){
				fprintf(fptr, "}");
				fclose(fptr);
			}
	}
}
