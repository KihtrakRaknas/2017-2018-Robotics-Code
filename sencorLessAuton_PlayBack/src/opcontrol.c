#include "main.h"
#include "global.h"
int OCcounter = 0;
#define thresh 10
int i = 0;

int playback[] = {0,1,0};
void operatorControl() {
	int scan  = 0;
	while (1) {
		while(i==playback[scan]){
			switch(playback[scan+1]){
				case TL:
					motorSet(BL, playback[scan+2]);
					motorSet(ML, playback[scan+2]);
					motorSet(TL, playback[scan+2]);
				case TR:
					motorSet(TR, playback[scan+2]);
					motorSet(MR, playback[scan+2]);
					motorSet(BR, playback[scan+2]);
				case ARMR:
					motorSet(ARML, -1 * playback[scan+2]);
					motorSet(ARMR, playback[scan+2]);
				case CLAWL:
					motorSet(CLAWL,playback[scan+2]);
					motorSet(CLAWR,-1 * playback[scan+2]);
				case MGR:
					motorSet(MGR, playback[scan+2]);
			}
		scan+=3;
		}
		i++;
		delay(20);
	}
}
