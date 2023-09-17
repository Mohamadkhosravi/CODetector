#include"systemClock.h"
void ClockInit(void){

//System clock selection fsys  =f HIRC
_cks0=1;
_cks1=1;
_cks2=1;

//HIRC frequency selection 2MHz
_hirc0=0;
_hirc1=0;

//HIRC oscillator enable control Disable
_hircen=0;

//High Frequency oscillator control when CPU is switched off Disable
_fhiden=0;

	

//HIRC frequency selection 2MHz
_hirc0=0;
_hirc1=0;

//HIRC oscillator enable control Disable
_hircen=1;

//High Frequency oscillator control when CPU is switched off Disable
_fhiden=1;

	
//System clock selection fsys  =f HIRC 2MHZ
_cks0=0;
_cks1=0;
_cks2=0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Wake-up
//An external falling edge on Port A
//A WDT overflow




//WDT function software control Enable
_we0=0;
_we1=1;
_we2=0;
_we3=1;
_we4=0;




//WDT time-out period selection 2^18/fLIRC
_ws0=1;
_ws1=1;
_ws2=1;



//PA7~PA0 wake-up function control
_pawu=0b00000000;

}