#include "BA45F5240.h"
#include "ADC.h" 
#include "NTC.h" 
#include "sevenSegment3DigitComplex.h"
#include "systemClock.h"
#include "GPIO.h"






#define pA_ppm 5212
#define co_set 1205 //ppm


#define VBattery(ADC_BAT)(1.20*(4095/ ADC_BAT)*100)

//test
char test_tm;
bit test;



//BUZ
int buz_delay;

	
//co
int ppm;
bit co;
bit co_falt;


//bat
float Vdd;
bit bat_low;
int V_ref;



int tm;
float V_ntc;
bit falt;

	
	
void OPAMPset (void);
//int ADC ( char pin);


void main()
{
	
ClockInit();
GPIOInit();
OPAMPInit();




do{

//LED_G=1;

//-----------------test but chek------------------------>>>
/*
_pac4=1;//SEG1, TEST BUT pin Input
_papu=0b00010000;//Pin pull-high function control
GCC_DELAY(100); 
if (_pa4==0)test=1;
_pac4=0;//SEG1, TEST BUT pin output
_papu=0b00000000;//Pin pull-high function control
*/

//-----------------test but chek------------------------<<<



//---------------------ADC read------------------------->>>



NTCToGND=1;



GCC_DELAY(1000);



//V_op0=Vdd*V_op0/4096;
//V_op1=Vdd*V_op1/4096;

//ppm=pA_ppm / V_op0 ;


//---------------------ADC read-------------------------<<<


LEDToGND=0;
//-------------------calculate Temperature--------------------------->>>


	//V_op0=29;
	ppm=19.2;

    //temp=0;
	Vdd=0;
	V_ref=0;
	GCC_DELAY(100000);
	
	S_ADC_Init();
  _vbgren=1;
  
  float temperatur=0.0;
  int cunter=0;
  int tm;
  
while(1){

//temperatur= temperature(S_READ_ADC(1),3.3);
 //shwoSegment((1.20*(4095/ VB_ADC))*100);  
// vbgren enable

_vbgren=1;
  
float VB_ADC=0;
//temperatur  =  1.20*(4095.000/ S_READ_ADC(4));
//	temperatur=temperatur*100.00;
 
	while(1){

   	_clrwdt();
      
 
    // shwoSegment(205);
    // oneDigit1();
     //oneDigit2();
 
       
     shwoSegment( S_READ_ADC(5)/10);
     
     
     
    cunter++;
     
	if(cunter>100)break;
     }
     cunter=0;
    
  
}
     Vdd=0;
//-------------------calculate Temperature-----------------------------<<<




//----------test but-----------

if (test==1){
	ppm=co_set+2;
	LED_R=!LED_R;
	_clrwdt();
	test_tm++;
	if(test_tm>5){
		test=0;
		test_tm=0;
		}	
	}
	
//----------test but-----------





//----------bat chek-----------

if (Vdd<3.00){
	bat_low=1;
	}else{
		bat_low=0;
		}
	
//----------bat chek-----------



//----------falt chek-----------

falt=co_falt==1 || bat_low==1;

if(falt){
	LED_Y=1;
	GCC_DELAY(10000); 
	LED_Y=0;
	GCC_DELAY(10000); 
	LED_Y=1;
	GCC_DELAY(10000);
	LED_Y=0;
	}else{
		LEDToGND=1;
		GCC_DELAY(10000); 
		LEDToGND=0;
		}
		
//----------bat chek-----------


	
//----------buz-----------		

while(co || falt){
	BUZ=1;
	GCC_DELAY(312);
	BUZ=0;
	GCC_DELAY(312);
	buz_delay++;
	
	if (falt==1 && buz_delay>1000)break;
	if (co==1 && buz_delay>3000)break;
	}
	
//----------buz-----------	




//----------co alarm chek-----------	
	
if (ppm>=co_set){
	co=1;
	LED_R=!LED_R;
	_clrwdt();
	}else{
		co=0;
		LED_R=0;
		}


//while(1){}

}while(co);

//----------co alarm chek-----------	




//PA7~PA0 wake-up function control
_pawu=0b00010000;

_clrwdt();

//Low Frequency oscillator control when CPU is switched off Disable
_fsiden=0;






	
}


