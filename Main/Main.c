#include "BA45F5240.h"
#include "ADC.h" 
#include "NTC.h" 
#include "sevenSegment3DigitComplex.h"
#include "systemClock.h"
#include "GPIO.h"
#include "Timer.h"



#define gainAmplifier1 7.666666666666667  //gainAmplifier1=1+(200k/15k)
#define RSHANT 15 //15k

//clock time is 8s
#define _8_HOURS    3600
#define _50_MINUTES 375
#define _10_MINUTES 75
#define _4_MINUTES  30

#define slope 0.04 //m = y2-y1/x2-x1
#define I(VOut)(VOut+((RS+(RF)/RS*(RF))*((R2/R3)+1)))
#define VBattery(ADC_BAT)( 1.20*(4095.000/ ADC_BAT))


#define BUZZER_ON   PWMSeter(1);
#define BUZZER_OFF  PWMSeter(0);


#define FULL_BATTERY 40
//#define MID_BATTERY  3.2
#define LOW_BATTERY  30

unsigned int alarmCounter;

#define limit1CO   ((alarmCounter>=3)&&(COValue>400))
//#define limit1CO   ((alarmCounter>=_4_MINUTES)&&(COValue>400))
#define limit2CO   ((alarmCounter>=_10_MINUTES)&&(COValue>125)) 
#define limit3CO   ((alarmCounter>=_50_MINUTES)&&(COValue>75)) 
#define limit4CO   ((alarmCounter>=_8_HOURS)&&(COValue>30))



typedef enum {

	IDLE,
	SINGLE,
	DOUBLE,
	LONGPRESS,
	NONPRESS

}buttonType;

buttonType key(void);		
float TempToPPMPercentage(float temperatur);



	
float VDD=0;
unsigned int COValue=0;

 int CO(float VCC,unsigned int ADC){
/*	OPAMPInit();
	OPAMPset ();
		_vbgren=1;
		_sda0en=1;
		_sda1en=1;*/
	
	float temperatur=0.0;
	float VAmplifier1=0.0;
	float COValue =0.0;

  
	//COV=S_READ_ADC(5);
	temperatur= (temperature(S_READ_ADC(1),VCC));
	VAmplifier1=ADC*((VCC)/4095);
	COValue=((((VAmplifier1)/gainAmplifier1*1000)/RSHANT)*1000)*slope;
	
         if ((-20<=temperatur<0))
		{
			return((-0.0075*(temperatur+20)+0.60))*COValue;	
		}
       	 if ((20<temperatur>=0))
		{
			return ((0.0025*(temperatur)+0.75))*COValue;
		}
	    if ((temperatur>=20)&&(temperatur<50))
		{
			return((0.0116*(temperatur-20)+0.100))*COValue;
		}
	     if ((temperatur>=50)&&(temperatur<=70))
		{
		  return((0.005*(temperatur-50)+0.135))*COValue;

		}
	
	
	
	
	
	
	
//	COValue=(TempToPPMPercentage(temperatur)*10)*COValue;
    	return COValue; 


}








     
	void buzzerBIB(char number){   
		  
		unsigned char cunter;
		unsigned char i;
		char index=number;
		
		if(number==0)index=1;
		
		for( i=0 ; i<number; i++){
			
		    cunter=0;
		    while(1){
				cunter++;
				GCC_DELAY(30000);
				if((cunter>=2)&&(cunter<8))BUZZER_ON
				else if((cunter>=8)&&(cunter<13))BUZZER_OFF
				else if(cunter>18)break ;
		    }
		    cunter=0;
		 
		}
		if(number>0)while(1){}
				
	
	}
	
	
	void main()
	{

		if(_to==0)
		{
			alarmCounter=0;
		}
		
		ClockInit();
		GPIOInit();
		GPIOToGNDCurentInit();
		OPAMPInit();
		S_ADC_Init();
		PTimerInit();
		
		//PWMSeter(0);
		void buzzerBIB(char number);
		
    	NTCToGND=1;
		
		_vbgren=1;
		_sda0en=1;
		_sda1en=1; 
		
		clearSegment();
		_papu4=1;
		_pawu4=1;
		_pawu=0b111000;	

		VDD = VBattery(S_READ_ADC(4));
		COValue = CO(VDD,S_READ_ADC(5));
		
   		NTCToGND=0;
		
		if((limit1CO)||(limit2CO)||(limit3CO)||(limit4CO)){
			
			while(1) 
			{
				 _clrwdt();
				 LEDToGND=1;
				 buzzerBIB(0);
			
			}
		}		
		if(COValue>30)
		{
			LEDToGND=1;
			buzzerBIB(1);
			alarmCounter++;
			LEDToGND=0;
			
		}
		else
		{
		  if(alarmCounter>0) alarmCounter--;	
		  PWMSeter(0);
		 
		}
       //yelow
        _pac3=0;
        _pa3=1;
      
     
	     if (VDD<=LOW_BATTERY)
	     {
				_pac3=0;
				_pa3=1;
				buzzerBIB(1);
				_pac3=0;
				_pa3=0;
			   buzzerBIB(1);
		  }
			
			_pac3=0;
			_pa3=1;	
			_pac3=0;
			_pa3=0;	
		
		while(1){ 
			
		
			
			
			 
		    buttonType buttonStatus;
		    buttonStatus=key();
		    
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
				     // PWMSeter(0); 
				}
				else if(buttonStatus==SINGLE)
				{
				    _clrwdt();
				     shwoSegment(COValue);
				}
				else if(buttonStatus==DOUBLE)
				{
					_clrwdt();	
					if(VDD >= FULL_BATTERY) shwoSegment(100);
					else if(VDD<LOW_BATTERY)shwoSegment(15);
					else shwoSegment(75);
				}
			
				else if(buttonStatus==LONGPRESS)
				{
					
					_clrwdt();
			       buzzerBIB(4);
			
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


/*	float TempToPPMPercentage(float temperatur)
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

}*/