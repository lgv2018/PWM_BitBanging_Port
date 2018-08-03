#include <PWM_BitBanging_Port.h>

Port PWM_BitBanging_Port(&DDRD,&PORTD);

void setup() 
{
    Port.PinValue[0] = B00000001;
    Port.PinValue[1] = B00000010;
    Port.PinValue[2] = B00000100;
    Port.PinValue[3] = B00001000;
    Port.PinValue[4] = B00010000;
    Port.PinValue[5] = B00100000;
    Port.PinValue[6] = B01000000;
    Port.PinValue[7] = B10000000;
}

void loop() 
{
   Port.run();
}