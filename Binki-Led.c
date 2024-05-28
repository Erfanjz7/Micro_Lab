#include "lpc17xx.h"
#define led Io1PIN
#define tled IO1DIR

void delay(unsigned int sec){
	unsigned int i;
	unsigned int j;
	for(i = 0; i < sec ; i++){
		for(j = 0; j < 20000 ; j++);
	}
	}
int main(){
	LPC_PINCON->PINSEL4 = 0;
	LPC_GPIO2->FIODIR = 1;
	while(1){
		LPC_GPIO2->FIOSET = 1;
		delay(100);
	  LPC_GPIO2->FIOCLR = 1;
		delay(100);
	}

}