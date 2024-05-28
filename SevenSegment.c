#include "lpc17xx_gpio.h"
//const uint8_t LedArray[] = {0x01 , 0x03 , 0x07 , 0x0E , 0x1C , 0x3B , 0x7B , 0xE0};
const uint8_t SevenSegment[10] = {0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F , 0x6F};
uint8_t counter = 0;

void delay() {
    for(uint16_t count = 0 ; count < UINT16_MAX ; count++){

       for(uint8_t count2 = 0 ; count2 < 100 ; count2++){

       }
    }
}

int main(){
    uint8_t count = 0;
    uint8_t countofdelay = 0;
    uint8_t count1 = 0;
    FIO_ByteSetDir(0 , 2 , 0xFF , 1);
    GPIO_SetDir(2 , (1<<1) , 1);


    while(1){
        GPIO_SetValue(2 , (1<<1));//2.1
        FIO_ByteSetValue(0 , 2 , SevenSegment[count]);//16ta32
        FIO_ByteClearValue(0 , 2 , ~SevenSegment[count]);
        delay();
        GPIO_ClearValue(2 , (1<<1));

        countofdelay++;
        if(countofdelay == 10){
            countofdelay = 0;
            count++;
            if(count == 10){
                count = 0;
                count1++;
            }
        }
    }
}