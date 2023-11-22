// Include necessary hardware-specific header files
#include "BA45F5240.h"
#include "ADC.h" 
#include "NTC.h" 
#include "sevenSegment3DigitComplex.h"
#include "systemClock.h"
#include "GPIO.h"
#include "Timer.h"
#include "CO.h"

//===================================
// Battery voltage calculation macro
#define VBattery(ADC_BAT)( 1.20*(4095.000/ ADC_BAT))

// Battery status thresholds
#define FULL_BATTERY 4
#define LOW_BATTERY  3
	
// Variable to keep track of alarm counts
unsigned int alarmCounter;


// Time constants for CO monitoring
#define _8_HOURS    3600
#define _50_MINUTES 375
#define _10_MINUTES 75
#define _4_MINUTES  30

// Minimum CO level allowed
#define MINIMUM_CO_ALLOWED 30

// CO level limits and corresponding time thresholds
#define LIMIT_1_CO   ((alarmCounter>=_4_MINUTES)&&(COValue>400))
#define LIMIT_2_CO   ((alarmCounter>=_10_MINUTES)&&(COValue>125)) 
#define LIMIT_3_CO   ((alarmCounter>=_50_MINUTES)&&(COValue>75)) 
#define LIMIT_4_CO   ((alarmCounter>=_8_HOURS)&&(COValue>30))

//===================================

// Enumeration for button press types
typedef enum {

	IDLE,
	SINGLE,
	DOUBLE,
	LONGPRESS,
	NONPRESS

}buttonType;



// Variables for storing sensor values			
float VDD=0.0;
unsigned short int temperatur=0;
unsigned int COValue=0;

//===================================

	
	void main()
	{
        //This condition is executed when the micro is turned on for the first time
		if(_to==0)
		{
			alarmCounter=0;
		}
			
		// Initialize hardware peripherals and configurations
		ClockInit();
		GPIOInit();
		GPIOToGNDCurentInit();
		OPAMPInit();
		S_ADC_Init();
		PTimerInit();
		
		// Function to read button press type
		buttonType key();
		void buzzerAlarm(char number);
		
		//Set up sensor and power-related configurations
		
    	NTCToGND=1;//The NTC GND pin is connected to the GND
  	
    	GPIOS_INPUT//config all GPIOS to INPUT
		WAKE_UP_KEY
    	_vbgren=1;//READ VBRG(voltage refrence 1.2V) for read VBattery ENABLE
		_sda0en=1;//OPAMP0 ENABLE
		_sda1en=1;//OPAMP1 ENABLE 
		
		// Read battery voltage, temperature, and CO level
		VDD = VBattery(S_READ_ADC(4));
	    temperatur= (temperature(S_READ_ADC(1),VDD));
     	COValue = ReadCO(VDD,S_READ_ADC(5),temperatur);
     	
     
   		NTCToGND=0;//The NTC GND pin is disconnected to the GND
   		
		// Perform actions based on CO levels
		if((LIMIT_1_CO)||(LIMIT_2_CO)||(LIMIT_3_CO)||(LIMIT_4_CO)){
			
		 // Trigger alarms and indicate danger	
			while(1) 
			{
				 _clrwdt();
				 LED_RED_ON
				 buzzerAlarm(0);
			     
			}
		}
				
		if(COValue > MINIMUM_CO_ALLOWED)
		{
		 // Trigger an alarm and increment the alarm counter	
		    LED_RED_ON
			buzzerAlarm(0);
			alarmCounter++;
	    	LED_RED_OFF
			
		}
		else
		{
		 // Decrease the alarm counter and turn off the buzzer	
		  if(alarmCounter>0) alarmCounter--;	
		  BUZZER_OFF
		 
		}
    
         BLINK_LED_GREEN
         
		// Check battery voltage and trigger alarms if it's too low
		if (VDD <= LOW_BATTERY)
		{
			LED_YELLOW_ON
			buzzerAlarm(0);
			LED_YELLOW_OFF
		
		}
		
		
		while(1){ 
			
		 // Handle button presses and perform actions accordingly
			 
		    buttonType buttonStatus;
		    buttonStatus=key();
		    
		    if(buttonStatus==NONPRESS)
			{
			// Enter low-power mode if no button is pressed	
			   _halt();			
			}
		    else
		    {
		    // Wake up from low-power mode and handle button press	
				WAKE_UP_KEY	
			    GPIOS_INPUT

		     	if(buttonStatus==IDLE)
				{
				  // Handle IDLE button press    
				}
				else if(buttonStatus==SINGLE)
				{
				// Handle SINGLE button press
				// Display CO value on a 3-digit 7-segment display
				    _clrwdt();
				     shwoSegment(COValue);
				}
				else if(buttonStatus==DOUBLE)
				{
				// Handle DOUBLE button press
				// Handle LONGPRESS button press	
					_clrwdt();	
					if(VDD >= FULL_BATTERY) shwoSegment(100);
					else if(VDD<LOW_BATTERY)shwoSegment(75);
					else shwoSegment(15);
				}
			
				else if(buttonStatus==LONGPRESS)
				{
				// Handle LONGPRESS button press	
				// Trigger a long press alarm	
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

   // Function to control the buzzer for alarms  
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
