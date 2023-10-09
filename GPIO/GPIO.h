
#include "BA45F5240.h"
//output
#define LED_Y	_pa1
#define LED_R	_pa3
#define BUZ		_pa6
 

 //output
#define LED_Y	_pa1
#define LED_R	_pa3
#define BUZ		_pa6
#define VBGREF	0b00011111
#define OPA0O	0b00101111
#define OPA1O	0b00111111


#define NTC	0b11110001	//_an1
#define an0	0b11110000
#define an2	0b11110010
#define an3	0b11110011



#define NTCToGND _isgs0
#define LEDToGND  _isgs1

#define	PULL_HIGH_KEY _papu4=1;
#define	WAKE_UP_KEY _pawu4=1;PULL_HIGH_KEY

#define LED_RED_ON 	LEDToGND=1;
#define LED_RED_OFF  LEDToGND=0;

#define LED_YELLOW_ON _pac3=0;_pa3=1;	
#define LED_YELLOW_OFF _pac3=0;_pa3=0;					

#define GPIOS_INPUT	 clearSegment();


#define BLINK_LED_GREEN  _pac3=0;_pa3=1;GCC_DELAY(4000);_pac3=0;_pa3=0;






  
  //#define Curent0 0b00000000
  
  
void GPIOToGNDCurentInit(void);	
//#define GPIOToGNDControl(GPIOCurentPin,State) GPIOCurentPin = State


//void GPIOToGNDCurentInit(char GPIOToGNDPin, char Curent)

 void GPIOInit(void);



