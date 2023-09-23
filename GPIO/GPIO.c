

#include <GPIO.h>




//ISINK 0,1

//void GPIOToGNDCurentInit(char GPIOToGNDPin, char Curent)
void GPIOToGNDCurentInit(void)
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Sink Current Generator
	
	//Sink current generator enable control
	_isgen=1;
	
	//Sink current generator control for ISINK0 pin
	//Current value (mA) = 50 + 10 × (ISGDATA0[4:0])
	_isgdata0=0b00000000;
	
	//Sink current generator control for ISINK1 pin
	//Current value (mA) = 50 + 5 × (ISGDATA1[4:0])
	_isgdata1=0b00000000;
	
	
	
	//Enable/Disable ISINK0 pin sink current control
	_isgs0=0;
	
	//Enable/Disable ISINK1 pin sink current control
	_isgs1=0;

/////////////////////////////////////////////////////////////////////////////////////////////////////	

}
	















void GPIOInit(void){
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
//Pin pull-high function control
_papu=0b00000000;
_pbpu=0b00000000;


//PxCn: I/O Port x Pin type selection
//0: Output
//1: Input
/*
_pac4=0;// SEG1 , TESTE

_pbc1=0;// SEG2
_pbc2=0;// SEG3
_pbc3=0;// SEG4
_pac2=0;// SEG5
_pac0=0;// SEG6


//LED_Y
_pac1=0;

//LED_R
_pac3=0;

//BUZ
_pac6=0;

//NTC
_pac7=0;
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////


//Source Current Selection
/*
Bit 7~6 SLEDC7~SLEDC6: PB4 source current selection
00: Source current=Level 0 (Min.)
01: Source current=Level 1
10: Source current=Level 2
11: Source current=Level 3 (Max.)
For the BA45F5240-2 device, these two bits are reserved and should be fixed at “00”.
Bit 5~4 SLEDC5~SLEDC4: PB3~PB0 source current selection
00: Source current=Level 0 (Min.)
01: Source current=Level 1
10: Source current=Level 2
11: Source current=Level 3 (Max.)
For the BA45F5240-2 device, these two bits are available for PB3~PB1.
Bit 3~2 SLEDC3~SLEDC2: PA7~PA4 source current selection
00: Source current=Level 0 (Min.)
01: Source current=Level 1
10: Source current=Level 2
11: Source current=Level 3 (Max.)
Bit 1~0 SLEDC1~SLEDC0: PA3~PA0 source current selection
00: Source current=Level 0 (Min.)
01: Source current=Level 1
10: Source current=Level 2
11: Source current=Level 3 (Max.)
Note: Users should refer to the Input/Output Characteristics section to obtain the exact value for
different applications
*/


/////////////////////////////////////////////////////////////////////////////////////////////////////////



//Pin Functions

//PA0 = SEG7
_pas00=0;
_pas01=0;

//PA1 = A1PI
_pas02=0;
_pas03=0;

//PA2 = SEG5
_pas04=0;
_pas05=0;

//PA3 = LED_R
_pas06=0;
_pas07=0;

//PA4 = SEG1 , TESTE
_pas10=0;
_pas11=0;

//PA6 = BUZZ
//PTP PWM OUTPUT
_pas14=1;
_pas15=0;

//PA7 = NTC
_pas16=0;
_pas17=1;
//PB2 = SEG3
_pbs04=0;
_pbs05=0;
//PB3 = RX
_pbs06=0;
_pbs07=0;
//PB1 =TX
_pbs02=0;
_pbs03=0;



	
//GPIOToGNDCurentInit();	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
//**************************************************************

}


 