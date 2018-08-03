/**********************************************************************************************
 * Arduino PWM_BitBanging_Port Library - Version 1.0
 * by William Bailes <williambailes@gmail.com> http://tinkersprojects.com/
 *
 * This Library is licensed under a GPLv3 License
 **********************************************************************************************/

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "PWM_BitBanging_Port.h"

/******************* SETUP *******************/

PWM_BitBanging_Port::PWM_BitBanging_Port()
{

}

PWM_BitBanging_Port::PWM_BitBanging_Port(byte *ddr,byte *Port)
{
    DDR = ddr;
    PORT = Port;
    PWM_BitBanging_Port::setup();
}


/******************* SET *******************/

void PWM_BitBanging_Port::setup()
{
    *DDR = B11111111;
    *PORT = B11111111;
}

/******************* COMMANDS *******************/

void PWM_BitBanging_Port::run()
{
    byte CurrentTime = (micros()*10)%255;
    byte PortValue = 0;
    PortValue += B00000001*(PinValue[0]>=CurrentTime);
    PortValue += B00000010*(PinValue[1]>=CurrentTime);
    PortValue += B00000100*(PinValue[2]>=CurrentTime);
    PortValue += B00001000*(PinValue[3]>=CurrentTime);
    PortValue += B00010000*(PinValue[4]>=CurrentTime);
    PortValue += B00100000*(PinValue[5]>=CurrentTime);
    PortValue += B01000000*(PinValue[6]>=CurrentTime);
    PortValue += B10000000*(PinValue[7]>=CurrentTime);
    *PORT = PortValue;
}
