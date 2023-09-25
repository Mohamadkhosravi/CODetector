#include "BA45F5240.h"
#include "ADC.h" 
#include "NTC.h" 
#include "sevenSegment3DigitComplex.h"
#include "systemClock.h"
#include "GPIO.h"
#include "EEPROM.h"
//#include <stdint.h>
#include "Timer.h"
//#include "OPAMP.h"


/*

#define RF 2 //*100k
#define R2 3 //*100k max 300k
#define R3 0 //*10k+10k
#define RS 1000
*/
//#define AVAmplifier1 995 //RS*RF/RS+RF   RS=1k external RF=150k external
#define gainAmplifier1 7.666666666666667
#define AVAmplifier2 13//1+R2/R3  R2=300k internal R3=10k internal



#define _8_HOURS  3600
#define _60_MINUTES 450
#define _240_MINUTES 1800
#define _240_MINUTES 1800
#define _50_MINUTES 375
#define _15_MINUTES 112
#define _10_MINUTES 75
#define _4_MINUTES 30
//#define MAXppm 1000
#define slope 0.04 //m = y2-y1/x2-x1
#define ConstA 0.000000025
#define ConstB 0.000003611
#define ConstC 0.000052182
#define ConstD 0.0151944

#define PPM(x)((ConstA*(x*x*x*x))-(ConstB*(x*x*x))+(ConstC*(x*x))+(ConstD*(x))+0.7)

#define I(VOut)(VOut+((RS+(RF)/RS*(RF))*((R2/R3)+1)))

#define VBattery(ADC_BAT)( 1.20*(4095.000/ ADC_BAT))

float VDD=0.0;
float COValue =0.0;
float temperatur=0.0;
float Amplifier1=0.0;
float VAmplifier1=0.0;

unsigned int alarmCounter;


#define KEY_PIN _pa4
#define SET 0
#define RESET 1
#define DEBOUNCE_THRESHOLD 2000
#define PRESS_STATE_TIMOUT 500

enum {

	IDLE,
	SINGLE,
	DOUBLE,
	LONGPRESS,
	NONPRESS

}buttonStatus;


unsigned int debounceCounter;
char keyState=0;
char pressLockFlag =2;
char pressFlag=0;
unsigned int keyCounter=0;
float TempToPPMPercentage(float temperatur);

 key(void);
void OPAMPset (void);		

	void main()
	{
	 	

		if(_to==0)
		{
			debounceCounter=0;
		}
			

	
		ClockInit();
		GPIOInit();
		GPIOToGNDCurentInit();
		OPAMPInit();
		S_ADC_Init();
		PTimerInit();
        PWMSeter(0);
	
	

	
			
		NTCToGND=1;
		LEDToGND=0;
		_vbgren=1;
		_sda0en=1;
		_sda1en=1; 
	
		
			
			
	
	
			clearSegment();
			_papu4=1;
			_pawu4=1;
			_pawu=0b111000;	
			pressFlag=0;
			debounceCounter=0;
			keyCounter=0;

	
	
        	VDD = VBattery(S_READ_ADC(4));
			temperatur= (temperature(S_READ_ADC(1),VDD));	
			Amplifier1=S_READ_ADC(5);
			VAmplifier1=(((Amplifier1*(VDD/4095))/gainAmplifier1*1000)/15)*1000;
			COValue=VAmplifier1*slope;
		    COValue=TempToPPMPercentage(temperatur)*COValue;
		    //COValue=PPM(temperatur)*COValue;
	
	
		while(1){
		   
			
			
			if(COValue>30)
			{
				alarmCounter++;
			}
			else
			{
			if(alarmCounter>0) alarmCounter--;	
			 PWMSeter(0);
			}
				
			if (((COValue>30)&&(alarmCounter>= _8_HOURS))||((COValue>70)&&(alarmCounter>_60_MINUTES))||((COValue>150)&&(alarmCounter>_10_MINUTES))||((COValue>400)&&(alarmCounter>_4_MINUTES)))
			{
		      //PWMSeter(1);
			
			}
		
		
			
			
	    	
		      key();
		    if(buttonStatus==NONPRESS)
			{
			   _halt();			
			}
		    else
		    {
				_papu4=1;
				_pawu4=1;
				_pawu=0b111000;	
				clearSegment();

		     	if(buttonStatus==IDLE)
				{
				   
				}
				else if(buttonStatus==DOUBLE)
				{
					_clrwdt();
						
					shwoSegment(COValue);
					
				}
				else if(buttonStatus==SINGLE)
				{
					_clrwdt();
				   
				}
				else if(buttonStatus==LONGPRESS)
				{	
					_clrwdt();
				
				
				}
			   
			
		    	 clearSegment();	
				_papu4=1;
				_pawu4=1;
		
	     	}
			clearSegment();	
			_papu4=1;
			_pawu4=1;
			_pawu=0b111000;	
		
			
		}
			
			
			
		   
	    
		
	}	

		
	
	
		

	 key(void){
		


		
		if(KEY_PIN == SET )	
		{
			
			debounceCounter++;
			buttonStatus  =IDLE;
			pressFlag=1;
		
			if ((pressLockFlag==1)&&(pressFlag==1))
			{
				keyState=(!keyState);
			    keyCounter=0;
				pressLockFlag=0;
			}
			if(debounceCounter > DEBOUNCE_THRESHOLD)
			{
				pressFlag=2;	
			
			}
			
		}
		if((KEY_PIN == RESET)&&(pressFlag ==1))
		{
			pressLockFlag=1;
			debounceCounter=0;
			
			clearSegment();
			_papu4=1;
			_pawu4=1;
		
		   if((keyState==1))
			{
		
		  	  buttonStatus  =DOUBLE;
		  	  keyCounter++;
		  	  
		  	  if(keyCounter>= PRESS_STATE_TIMOUT)
		  	  {
		  	  	debounceCounter=0;
		  	  	pressFlag=0;
		  	  	keyCounter=0;
		  	  }
			 // pressCount=1;
				
			}
		    if((keyState==0))
		    {
				buttonStatus= SINGLE;
				keyCounter++;
				if(keyCounter>= PRESS_STATE_TIMOUT)
				{
					debounceCounter=0;
					pressFlag=0;
					keyCounter=0;
				}
				
		    }
		
		    clearSegment();	
		   
			_papu4=1;
			_pawu4=1;
		
		
		}  
		if((KEY_PIN == RESET)&&(pressFlag ==2))
		{    
			buttonStatus =LONGPRESS;
			keyCounter++;
			
		     if(keyCounter>= PRESS_STATE_TIMOUT)
		  	  {
		  	  	debounceCounter=0;
		  	  	pressFlag=0;
		  	  	keyCounter=0;
		  	  }
			
			
		}
		
		if((pressFlag ==0))
		{
			buttonStatus= NONPRESS;			
		}
		
		
	 }  	   	 
	

	float TempToPPMPercentage(float temperatur)
	{

		    if ((temperatur<0)&&(temperatur>=-20))
			{
				return((-0.0075*(temperatur+20)+0.60));	
			}
		     if ((temperatur>=0)&&(temperatur<20))
			{
				return ((0.0025*(temperatur)+0.75));
			}
		    if ((temperatur>=20)&&(temperatur<50))
			{
				return((0.0116*(temperatur-20)+0.100));
			}
		    if ((temperatur>=50)&&(temperatur<=70))
			{
			  return((0.005*(temperatur-50)+0.135));
			}
	
	}