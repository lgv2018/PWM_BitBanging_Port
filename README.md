# PWM_BitBanging_Port Library (working progress)
[https://tinkersprojects.com/](https://tinkersprojects.com/)

This Library is to control all pins on a port as a PWM signal which is known as bit-banging. Bit-banging is when the microcontroller generates the signal and not external hardware. This can work but it mean the microcontroller cannot preform many other tasks. If the microcontroller has other tasks, the PWM bit-banging may not work.
The PWM signal from this library is not true PWM but implemented correctly, it can make a signal close to it. The signal will not have a much lower frequency from the original PWM but a better one than individual pins. 

## Functions

#### PWM_BitBanging_Port(byte *ddr,byte *Port)
This function used to setup the class to be used thought the program. *byte *ddr* is for the port setup, use the following variable in this location: DDRA=>for port A, DDRB=>for port B, DDRC=>for port C,... etc.  *byte *Port* is the port variable, use the following variable in this location: PORTA=>for port A, PORTB=>for port B, PORTC=>for port C,... etc. 
#### PWM_BitBanging_Port()
This function used to setup the class to be used thought the program. *byte* DDR* and *byte* PORT* will need to be set and *void setup()* in setup to use this library.
#### void setup()
This function is to set the pins to output pins. *PWM_BitBanging_Port(byte *ddr,byte *Port)* calls this function when it needs too. This function only needs to run if *PWM_BitBanging_Port()* is used to setup the class and  *byte* DDR/byte* PORT* have been set manually. Most of the time, this function will not need to be called.
#### void run()
This function needs as much as possible. If this function does not run as much as possible, the light may start flickering and the PWM will not work correctly.


## Variables

#### byte* DDR
This variable is for the port setup, use the following variable in this location: DDRA=>for port A, DDRB=>for port B, DDRC=>for port C,... etc.
#### byte* PORT
This variable is the port variable, use the following variable in this location: PORTA=>for port A, PORTB=>for port B, PORTC=>for port C,... etc. 
#### byte PinValue[8]
This variable is all the pin values for each of the pins. Change these values to change the PWM of that pin. To change the value of *pin0* to *125* then *PWM_BitBanging_Port.PinValue[0] = 125;* 


## Example
### Example 1

```c++
#include <PWM_BitBanging_Port.h>

PWM_BitBanging_Port Port(&DDRD,&PORTD);

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
```

### Example 2 (Random)

```c++
#include <PWM_BitBanging_Port.h>

PWM_BitBanging_Port Port(&DDRD,&PORTD);

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
```
