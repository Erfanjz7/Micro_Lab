#include "LPC17xx.h"

#define LED_PIN (1 << 16) 
#define BUTTON_PIN (1 << 10) 

void delay(void) {
    for (volatile uint32_t i = 0; i < 1000000; i++); 
}

void LED_On(void) {
    LPC_GPIO1->FIOSET = LED_PIN;
}

void LED_Off(void) {
    LPC_GPIO1->FIOCLR = LED_PIN;
}

int main(void) {
    
    LPC_GPIO1->FIODIR |= LED_PIN;
    LPC_GPIO2->FIODIR &= ~BUTTON_PIN;

    while (1) {
        if (!(LPC_GPIO2->FIOPIN & BUTTON_PIN)) {
            for (int i = 0; i < 3; i++) {
                LED_On();
                delay();
                LED_Off();
                delay();
            }
        }
    }
}