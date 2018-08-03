#include <PWM_BitBanging_Port.h>

Port PWM_BitBanging_Port(&DDRD,&PORTD);

unsigned long lasttime;

void setup() 
{
    Port.PinValue[0] = random(2560)%255;
    Port.PinValue[1] = random(2560)%255;
    Port.PinValue[2] = random(2560)%255;
    Port.PinValue[3] = random(2560)%255;
    Port.PinValue[4] = random(2560)%255;
    Port.PinValue[5] = random(2560)%255;
    Port.PinValue[6] = random(2560)%255;
    Port.PinValue[7] = random(2560)%255;
    lasttime = millis();
}

void loop() 
{
    if(millis()>lasttime+1000)
    {
        Port.PinValue[0] = random(2560)%255;
        Port.PinValue[1] = random(2560)%255;
        Port.PinValue[2] = random(2560)%255;
        Port.PinValue[3] = random(2560)%255;
        Port.PinValue[4] = random(2560)%255;
        Port.PinValue[5] = random(2560)%255;
        Port.PinValue[6] = random(2560)%255;
        Port.PinValue[7] = random(2560)%255;
        lasttime = millis();
    }
   Port.run();
}