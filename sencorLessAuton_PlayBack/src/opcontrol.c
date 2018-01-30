#include "main.h"
#include "global.h"
int OCcounter = 0;
#define thresh 10
int i = 0;//Keeps track of time elapsed

int playback[] = {0,1,0};
void operatorControl() {
	int scan  = 0;
	while (1) {
		while(i==playback[scan]){//playback[scan] represents the time the event happens in. This is a while loop because multiple events may take place in the same frame
			switch(playback[scan+1]){//playback[scan+1] is a motorport which is being modified
				case TL://controls left drive motors
					motorSet(BL, playback[scan+2]);
					motorSet(ML, playback[scan+2]);
					motorSet(TL, playback[scan+2]);
				case TR://controls right drive motors
					motorSet(TR, playback[scan+2]);
					motorSet(MR, playback[scan+2]);
					motorSet(BR, playback[scan+2]);
				case ARMR: //controls lift motors
					motorSet(ARML, -1 * playback[scan+2]);
					motorSet(ARMR, playback[scan+2]);
				case CLAWL://controls intake motors
					motorSet(CLAWL,playback[scan+2]);
					motorSet(CLAWR,-1 * playback[scan+2]);
				case MGR://controls mobile goal lift motors
					motorSet(MGR, playback[scan+2]);
			}
		scan+=3;//Go to the next set of 3 data points in the array
		}
		i++;//Move forward in time
		delay(20);//creates a constant interval between frames
	}
}
