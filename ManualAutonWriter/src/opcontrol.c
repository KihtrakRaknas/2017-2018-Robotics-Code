#include "main.h"

void debug(int motorPort, int value);
int move(int motorPort, int value);
double movePot(int motorPort, int potPort, int PotValue, bool SetMotor);
double moveEncode(int motorPort, Encoder encodePort, int EncodeValue, bool SetMotor);

bool motorIsDrive(int m){
	if(m == 2 || m == 3)
		return true;
	return false;
}

//Encoders are named in main.h
//Encoders are initialized in init.c

Encoder encodeName(int m){
	if(m==2)
		return encodeOne;
	return encodeTwo;
	/*else if(m==2)
		return encodeTwo;
	else if(m==3)
		return encodeThree;
	//Same as saying else if(m==[last encoder value])
	return encodeFour;
	return encodeOne;*/
}

int potPort(int Motorport){
	return Motorport;
	/*if(m==5)
		return 5;
	else if(m==6)
		return 6;
	else if(m==7)
		return 7;
	//Same as saying else if(m==[last encoder value])
	return 8;*/
}

//first num is motor second is sensor val
// if motor is 0 then event is over (no need to type a value)
int playBack[] = {2,0,3,0,0,2,-1278,3,1276,0,2,-1600,3,867,0,2,-2588,3,1843,0,2,-2180,3,2148,0,2,-4182,3,4133,0,3,4311,0,2,-6192,3,6251,0};//drive in a square

void operatorControl() {
	// while(1){
	// 	debug(2,0);
	// 	debug(3,0);
	// }
	int i = 0;
	while(i!=sizeof(playBack)/sizeof(int)){
		int startI = i;
		bool running = true;
		while (running == true) {
			i=startI;
			running = false;
			while(playBack[i]!=0){
				debug(playBack[i], playBack[i+1]);
				if (move(playBack[i],playBack[i+1])!=0)
					running = true;
				i+=2;
			}
			i++;
			//delay(5000);
		}

	}
}

void debug(int motorPort, int value){
	delay(200);
	if(motorIsDrive(motorPort))
		printf("Motor:%d Pos: %d Value %d\n",motorPort,value,encoderGet(encodeName(motorPort)));
	else
		printf("Motor:%d Pos: %d Value %d\n",motorPort,value,analogRead(potPort(motorPort)));
}

int move(int motorPort, int value){
	if(motorIsDrive(motorPort))
		return moveEncode(motorPort, encodeName(motorPort), value, true);
	else
		return movePot(motorPort, potPort(motorPort), value, true);
}

#define THRESHforPot 0 //VEX potentiometers read between 0 and 4095
#define THRESHforPotMotor 15 //found 13 through trial and error
#define potMaxSpeed 30
double movePot(int motorPort, int potPort, int PotValue, bool SetMotor){ //When "Vex" is facing away from the motor
	double SpeedOfMotor = 0;
	if ((PotValue-THRESHforPot) > analogRead(motorPort))
		SpeedOfMotor = (double)(analogRead(motorPort)-(PotValue-THRESHforPot))/4095*100;//positive When "Vex" is facing away from the motor
	else if (analogRead(motorPort) > (PotValue+THRESHforPot))											//255 is a randomly choosen number
		SpeedOfMotor = (double)(analogRead(motorPort)-(PotValue+THRESHforPot))/4095*100;//negitive When "Vex" is facing away from the motor
	if(-THRESHforPotMotor<=SpeedOfMotor&&SpeedOfMotor<=THRESHforPotMotor)
		SpeedOfMotor=0;
	if(SpeedOfMotor>potMaxSpeed)
		SpeedOfMotor=potMaxSpeed;
	if(SpeedOfMotor<-potMaxSpeed)
		SpeedOfMotor=-potMaxSpeed;
	printf("%f",SpeedOfMotor);
	if(SetMotor)
		motorSet(motorPort, SpeedOfMotor);
	return SpeedOfMotor;
}

#define THRESHforEndcode 0 //There are 360 ticks in one revolution
#define THRESHforEndcodeMotor 50 //found 9 through trial and error
double moveEncode(int motorPort, Encoder encodePort, int EncodeValue, bool SetMotor){ //When "Vex" is facing away from the motor
	double SpeedOfMotor = 0;
	if ((EncodeValue-THRESHforEndcode) > encoderGet(encodePort))
		SpeedOfMotor = -1*(double)(encoderGet(encodePort)-(EncodeValue-THRESHforEndcode))/360*100;//negitive When "Vex" is facing away from the motor
	else if (encoderGet(encodePort) > (EncodeValue+THRESHforEndcode))
		SpeedOfMotor = -1*(double)(encoderGet(encodePort)-(EncodeValue+THRESHforEndcode))/360*100;//positive When "Vex" is facing away from the motor
	if(-THRESHforEndcodeMotor<=SpeedOfMotor&&SpeedOfMotor<=THRESHforEndcodeMotor)
		SpeedOfMotor=0;
	printf("%f",SpeedOfMotor);
	if(SetMotor){
		motorSet(motorPort, SpeedOfMotor);
		if(motorPort == 2) //For one ecoder per side set up
			motorSet(1, SpeedOfMotor); //For one ecoder per side set up
		else if(motorPort == 3) //For one ecoder per side set up
			motorSet(10, SpeedOfMotor); //For one ecoder per side set up
	}
	//printf("%f",SpeedOfMotor);
	return SpeedOfMotor;
}
