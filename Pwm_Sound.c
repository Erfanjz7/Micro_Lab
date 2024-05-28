#include "LPC17xx.h"

void PWM_Init() {
    // 1. Enable power for PWM1
    LPC_SC->PCONP |= (1 << 6);

    // 2. Select P2.0 as PWM1.1 output (PWM1 channel 1)
    LPC_PINCON->PINSEL4 &= ~(3 << 0); // Clear bits 0 and 1
    LPC_PINCON->PINSEL4 |= (1 << 0);  // Set bit 0

    // 3. Set PWM1 clock prescaler
    LPC_PWM1->PR = 0; // Prescale to 0 to count in CPU cycles

    // 4. Set PWM1 period for 10 kHz
    // Assuming the system clock (CCLK) is 100 MHz
    LPC_PWM1->MR0 = 10000; // Period = 100 MHz / 10 kHz

    // 5. Set initial duty cycle for PWM1.1 (e.g., 50% duty cycle)
    LPC_PWM1->MR1 = 5000; // 50% of MR0

    // 6. Enable PWM Match register 0 and 1 latch
    LPC_PWM1->LER = (1 << 0) | (1 << 1);

    // 7. Enable PWM1
    LPC_PWM1->TCR = (1 << 0) | (1 << 3); // Enable counter and PWM mode

    // 8. Enable PWM1 output for channel 1
    LPC_PWM1->PCR = (1 << 9); // Enable PWM1 output
}

int main() {
    PWM_Init();

    while(1) {
        // Main loop can be used to adjust duty cycle or other tasks
    }

    return 0;
}
