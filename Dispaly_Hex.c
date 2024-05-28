
#include <LPC17xx.h>

unsigned int delay, count = 0, switchcount = 0, j, i;

unsigned int Disp[10] = {255, 12, 6263, 6207, 6284, 6331, 6395, 15, 6399, 6287};

#define ALLDISP 0x00180000 //select all display 
#define DATAPORT 0x00000ff0 //P0.4 to p0.11: data lines connected to drive 7segment

void delay_ms(unsigned int x){
	unsigned int j, k;
	for(j =0; j < x; j++)
		for(k =0; k < x; k++);
}

int main(void){

	LPC_GPIO0 -> FIODIR = 0xffff;
	
	while(1){
		
		for(j = 0; j < 3; j++)
		for(delay = 0; delay < 30000;delay++);
		
		switchcount++;
		if(switchcount == 0x10){
			switchcount = 0;
			LPC_GPIO0 -> FIOPIN = 2048;
		}
		

		for(i = 0; i < 10; i++){
			LPC_GPIO0 -> FIOPIN = Disp[i];
			delay_ms(3000);
			LPC_GPIO0 -> FIOPIN = 0;		
		}
		
			for(i = 10; i > 0; i--){
				LPC_GPIO0 -> FIOPIN = Disp[i];
				delay_ms(3000);
				LPC_GPIO0 -> FIOPIN = 0;
		}
	}
}
