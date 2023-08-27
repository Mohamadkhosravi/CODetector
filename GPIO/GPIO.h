
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
  
  //#define Curent0 0b00000000
  
  
void GPIOToGNDCurentInit(void);	
//#define GPIOToGNDControl(GPIOCurentPin,State) GPIOCurentPin = State


//void GPIOToGNDCurentInit(char GPIOToGNDPin, char Curent)

 void GPIOInit(void);



