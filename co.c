#include "BA45F5240.h"
#include "ADC.h" 
#include "NTC.h" 
#include "sevenSegment3DigitComplex.h"
#include "systemClock.h"
#include "GPIO.h"
#include "EEPROM.h"
#include <stdint.h>
#include "Timer.h"
//extern void movir();
//#include "OPAMP.h"
 
#define pA_ppm 5212
#define co_set 1205 //ppm


/*

#define RF 2 //*100k
#define R2 3 //*100k max 300k
#define R3 0 //*10k+10k
#define RS 1000
*/
//#define AVAmplifier1 995 //RS*RF/RS+RF   RS=1k external RF=150k external
#define gainAmplifier1 6.666666666666667
#define AVAmplifier2 13//1+R2/R3  R2=300k internal R3=10k internal



#define _8_HOURS  3600
#define _240_MINUTES 1800
#define _50_MINUTES 375
#define _15_MINUTES 112


//#define MAXppm 1000
#define slope 0.0275 //m = y2-y1/x2-x1
#define ConstA 0.000000025
#define ConstB 0.000003611
#define ConstC 0.000052182
#define ConstD 0.0151944
//(ConstA*(x*x*x*x))-
#define PPM(x)((ConstA*(x*x*x*x))-(ConstB*(x*x*x))+(ConstC*(x*x))+(ConstD*(x))+0.7)


#define I(VOut)(VOut+((RS+(RF)/RS*(RF))*((R2/R3)+1)))

#define VBattery(ADC_BAT)( 1.20*(4095.000/ ADC_BAT))

float VDD=0.0;
float COValue =0.0;
float temperatur=0.0;
float Amplifier1=0.0;
float tempAmplifier1=0.0;
float VAmplifier1=0.0;






void OPAMPset (void);
int cunter=0;
char i;


unsigned int alarmCounter;
char alarmCounterFlag;

#define KEY_PIN _pa4
#define SET 0
#define RESET 1
#define DEBOUNCE_THRESHOLD 5000
#define STATE_TIMOUT 500

enum {

	IDLE,
	SINGLE,
	DOUBLE,
	LONGPRESS,
	NONPRESS

}buttonStatus;

int pressCount;
int debounceCounter;
char keyState=0;
pressCount = 0;
char pressLockFlag =2;
char pressFlag=0;
unsigned int keyCounter=0;


 key(void);
void OPAMPset (void);		

	void main()
	{
	 	

		if(_to==0)
		{
		
		
			//currentTime=0;	
			
			debounceCounter=0;
			cunter=0;
			alarmCounterFlag =0;
		  
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
		//_clrwdt();
		
		
		clearSegment();

			NTCToGND=1;
			LEDToGND=0;
			S_ADC_Init();

	    	_vbgren=1;
			_sda0en=1;
			_sda1en=1; 
		
			VDD = VBattery(S_READ_ADC(4));

			// vbgren enable
			_vbgren=1;
			temperatur= temperature(S_READ_ADC(1),VDD);	
			
			tempAmplifier1=0;
			Amplifier1=0;
			
			for (i=0;i<10;i++)
			{
				Amplifier1=S_READ_ADC(5);
				tempAmplifier1=tempAmplifier1+Amplifier1;
			
			}
		     Amplifier1=tempAmplifier1/10;
		     VAmplifier1=(((Amplifier1*(VDD/4095))/gainAmplifier1*1000)/15)*1000;
		     COValue=VAmplifier1*slope;


		//	shwoSegment(COValue * PPM(temperatur/10));
	
			clearSegment();
			_papu4=1;
			_pawu4=1;
			_pawu=0b111000;	
			
			pressFlag=0;
			
			debounceCounter=0;
		
		 	
	      cunter=0;
			
			keyCounter=0;
			
			
		if ((COValue>30)&&(alarmCounter>= _8_HOURS)){
		
		}
		else if ((COValue>70)&&(alarmCounter>= _240_MINUTES)){
		
		}
		else if ((COValue>150)&&(alarmCounter>=_50_MINUTES)){
		
		}
		else if ((COValue>400)&&(alarmCounter>= _15_MINUTES)){
		
		}
		else
		{	
		
		}
		
		if(alarmCounterFlag==1)
		{	
	    	alarmCounter++;
		}
			
		while(1){
			
			
	    	key();
		
		    if(buttonStatus==NONPRESS)
			{
			
					_halt();			
			}
		    else
		    {
				key();
				_papu4=1;
				_pawu4=1;
				_pawu=0b111000;	
				clearSegment();

		     	if(buttonStatus==IDLE)
				{
					clearSegment(); 
					_papu4=1;
					_pawu4=1; 
				}
				else if(buttonStatus==DOUBLE)
				{
					_clrwdt();
					clearSegment();
				   // shwoSegment(COValue * PPM(temperatur/10));
				   shwoSegment(COValue);
					clearSegment();
					
				}
				else if(buttonStatus==SINGLE)
				{
					_clrwdt();
					clearSegment();
				    shwoSegment(temperatur/10);
					clearSegment();
				}
				else if(buttonStatus==LONGPRESS)
				{
					_clrwdt();
					clearSegment();
					shwoSegment(333);
					clearSegment(); 
					cunter=0;
					_papu4=1;
					_pawu4=1; 
					
				}
			   
			
		    	clearSegment();	
				_papu4=1;
				_pawu4=1;
		
	     	}
				clearSegment();	
				_papu4=1;
				_pawu4=1;
				_pawu=0b111000;	
				cunter=0;
			
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
			cunter=0;
			clearSegment();
			_papu4=1;
			_pawu4=1;
		
		   if((keyState==1))
			{
		
		  	  buttonStatus  =DOUBLE;
		  	  keyCounter++;
		  	  
		  	  if(keyCounter>= STATE_TIMOUT)
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
		   	  if(keyCounter>= STATE_TIMOUT)
		  	  {
		  	  	debounceCounter=0;
		  	  	pressFlag=0;
		  	  	keyCounter=0;
		  	  }
		   	 
		    }
		
		    clearSegment();	
		    cunter=0;
			_papu4=1;
			_pawu4=1;
		
		
		}  
		if((KEY_PIN == RESET)&&(pressFlag ==2))
		{    
			buttonStatus =LONGPRESS;
			keyCounter++;
			
		     if(keyCounter>= STATE_TIMOUT)
		  	  {
		  	  	debounceCounter=0;
		  	  	pressFlag=0;
		  	  	keyCounter=0;
		  	  }
			
			
		//	if (pressTimer>=200)
	
		}
		
		if((pressFlag ==0))
		{
			buttonStatus= NONPRESS;			
		}
		
		
	 }  	   	 
	

		
	

	
	
