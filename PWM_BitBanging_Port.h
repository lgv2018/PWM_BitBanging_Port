
#ifndef PWM_BitBanging_Port_h
#define PWM_BitBanging_Port_h

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <wiring.h>
#endif


class PWM_BitBanging_Port
{
    public:
        PWM_BitBanging_Port();
        PWM_BitBanging_Port(byte *ddr,byte *Port);
        void setup();
        void run();
        byte* DDR;
        byte* PORT;
        byte PinValue[8];
    private:  
};

#endif 
