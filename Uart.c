#include <LPC17xx.h>
#include "uart.h"

void delay_ms(usnsigned int x){
   unsigned int j , k;
   for(j = 0 ; j < x ; j++)
       for(k = 0 ; k < x ; k++);
}

int main(){
   UART0_Init ();
   while(1){
   UART0_SendString("Erfan UwU \n");
   delay_ms(1000);
   }
}