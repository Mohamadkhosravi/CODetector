#include "BA45F5240.h"
#include "ADC.h" 
#include "NTC.h" 
#include "sevenSegment3DigitComplex.h"
#include "systemClock.h"
#include "GPIO.h"
#include "Timer.h"
#include "CO.h"



//#define I(VOut)(VOut+((RS+(RF)/RS*(RF))*((R2/R3)+1)))
#define VBattery(ADC_BAT)( 1.20*(4095.000/ ADC_BAT))
#define FULL_BATTERY 4
#define LOW_BATTERY  3



unsigned int alarmCounter;


//clock time is 8s
#define _8_HOURS    3600
#define _50_MINUTES 375
#define _10_MINUTES 75
#define _4_MINUTES  30


#define MINIMUM_CO_ALLOWED 30

#define LIMIT_1_CO   ((alarmCounter>=_4_MINUTES)&&(COValue>400))
#define LIMIT_2_CO   ((alarmCounter>=_10_MINUTES)&&(COValue>125)) 
#define LIMIT_3_CO   ((alarmCounter>=_50_MINUTES)&&(COValue>75)) 
#define LIMIT_4_CO   ((alarmCounter>=_8_HOURS)&&(COValue>30))



typedef enum {

	IDLE,
	SINGLE,
	DOUBLE,
	LONGPRESS,
	NONPRESS

}buttonType;

buttonType key(void);
			
float VDD=0.0;
unsigned short int temperatur=0;
unsigned int COValue=0;


	
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
		void buzzerAlarm(char number);
		
    	NTCToGND=1;
		
		_vbgren=1;
		_sda0en=1;
		_sda1en=1; 
		
    	GPIOS_INPUT
		WAKE_UP_KEY
		
		//_pawu=0b111000;	
		
    	_vbgren=1;
		_sda0en=1;
		_sda1en=1; 
		
		VDD = VBattery(S_READ_ADC(4));
	    temperatur= (temperature(S_READ_ADC(1),VDD));
     	COValue = ReadCO(VDD,S_READ_ADC(5),temperatur);
     	
   		NTCToGND=0;
	
		if((LIMIT_1_CO)||(LIMIT_2_CO)||(LIMIT_3_CO)||(LIMIT_4_CO)){
			
			while(1) 
			{
				 _clrwdt();
				 LED_RED_ON
				 buzzerAlarm(0);
			     
			}
		}
				
		if(COValue > MINIMUM_CO_ALLOWED)
		{
		    LED_RED_ON
			buzzerAlarm(0);
			alarmCounter++;
	    	LED_RED_OFF
			
		}
		else
		{
		  if(alarmCounter>0) alarmCounter--;	
		  BUZZER_OFF
		 
		}
    
         BLINK_LED_GREEN
		
		if (VDD <= LOW_BATTERY)
		{
			LED_YELLOW_ON
			buzzerAlarm(0);
			LED_YELLOW_OFF
		
		}
		
		
		while(1){ 
			
		
		
			 
		    buttonType buttonStatus;
		    buttonStatus=key();
		    
		    if(buttonStatus==NONPRESS)
			{
			   _halt();			
			}
		    else
		    {
				WAKE_UP_KEY	
			    GPIOS_INPUT

		     	if(buttonStatus==IDLE)
				{
				     
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
					else if(VDD<LOW_BATTERY)shwoSegment(75);
					else shwoSegment(15);
				}
			
				else if(buttonStatus==LONGPRESS)
				{
					
					_clrwdt();
			       buzzerAlarm(4);
			
				}
		    

				GPIOS_INPUT
			    WAKE_UP_KEY	
		
	     	}
	     	
			GPIOS_INPUT
			WAKE_UP_KEY	
	

		}
  
		
	}	

     
	void buzzerAlarm(char number){   
		  
		unsigned char cunter;
		unsigned char i;
		char index=number;
		
		if(number==0)index=1;
		
		for( i=0 ; i<index; i++){
			
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
