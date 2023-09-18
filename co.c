#include "BA45F5240.h"
#include "ADC.h" 
#include "NTC.h" 
#include "sevenSegment3DigitComplex.h"
#include "systemClock.h"
#include "GPIO.h"
#include "EEPROM.h"
#include <stdint.h>
#include "Button.h"
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

//#define MAXppm 1000
#define slope 0.0275 //m = y2-y1/x2-x1
/*
#define ConstA 0.000000056
#define ConstB 0.000007217
#define ConstC 0.000202579
#define ConstD 0.0133869
*/

#define ConstA 0.000000025
#define ConstB 0.000003611
#define ConstC 0.000052182
#define ConstD 0.0151944

//(ConstA*(x*x*x*x))-
#define PPM(x)((ConstA*(x*x*x*x))-(ConstB*(x*x*x))+(ConstC*(x*x))+(ConstD*(x))+0.7)
#define I(VOut)(VOut+((RS+(RF)/RS*(RF))*((R2/R3)+1)))
//temperatur  =  1.20*(4095.000/ S_READ_ADC(4));
#define VBattery(ADC_BAT)( 1.20*(4095.000/ ADC_BAT))


float COValue =0.0;
float temperatur=0.0;
float Amplifier1=0.0;
float tempAmplifier1=0.0;
float VAmplifier1=0.0;
unsigned int TimerValue=0;
int my_E ;
int my_E2;

void OPAMPset (void);
int cunter=0;
char i;
	int currentTime	;
int state;
 enum {

	IDLE,
	SINGLE,
	DOUBLE,
	LONGPRESS

}buttonStatus;

	void main()
	{
	 	

		if(_to==0)
		{
		 my_E=0;
		 my_E2=0;
		 currentTime=0;	
		 state=0;
	     debounceCounter=0;
		 
		 
		  //buttonStatus:BUTTON_STATE_IDLE;
		}
			
			
		ClockInit();
		GPIOInit();
		GPIOToGNDCurentInit();
		OPAMPInit();
		S_ADC_Init();

		NTCToGND=1;
		LEDToGND=0;

		_vbgren=1;
		_sda0en=1;
		_sda1en=1; 
		_clrwdt();
		
		
		clearSegment();

		char pressFlag=0;
		while(1)
		{	
			
	    	buttonStatus =IDLE;
			clearSegment();
			_papu4=1;
			_pawu4=1;
			_pawu=0b111000;	
			char dot=0;
		    pressCount = 0;
		char flag =1;
		while(1){	
				_clrwdt();
				
				_papu4=1;
			    _pawu4=1;
			   _pawu=0b111000;	
			   clearSegment();
			   
	
			
			
			    if(_pa4 == 0 )	
				{
				  debounceCounter++;
				  
					 if ((flag==1)&&(pressFlag==0))
					 {
					  dot=(!dot);
					  flag=0;
					 }
					 if(debounceCounter>10000)
					 {
					  pressFlag=1;	
					 	
					 }
				 
	
				}
				if((_pa4 == 1)&&(pressFlag ==0))
				{
				  flag=1;
				 debounceCounter=0;
		             cunter=0;
			       clearSegment();
		             _papu4=1;
				      _pawu4=1;
		               
		               	
		               if((dot==1))
						{
							
							buttonStatus  =DOUBLE;
							debounceCounter=0;
							pressCount=1;
							
						}
	                    if((dot==0))
	                    {
		                    clearSegment();
							buttonStatus =SINGLE;	
	                    	
	                    }
		               		
				        
					    
				    
			
				      if(	buttonStatus==DOUBLE)
				      {
				      	 clearSegment();
				      	 shwoSegment(222);
				      	 clearSegment();
				      }
				      if(buttonStatus==SINGLE)
				      {
				      	clearSegment();
				      	 shwoSegment(111);
				      	 clearSegment();
				      	
				      	}
		            
			        
					    clearSegment();	
				        cunter=0;
						_papu4=1;
						_pawu4=1;
	
			        
		             	}  
		         if((_pa4 == 1)&&(pressFlag ==1))
				{    
					
				
						
		          	clearSegment();
				      	 shwoSegment(333);
				      	 clearSegment(); 
				      	   cunter=0;
						_papu4=1;
						_pawu4=1; 
						
						
				
		             	
				}    	
		             	 
			
		
		      }  
		}	
		
		
	}	
	 // goto start;
		/*while(1)
		{
				
			shwoSegment(111);
			
		
		}*/
			
		/*
		tempAmplifier1=0;
		Amplifier1=0;
		
		for (i=0;i<10;i++)
		{
			Amplifier1=S_READ_ADC(5);
			tempAmplifier1=tempAmplifier1+Amplifier1;
		
		}
		Amplifier1=tempAmplifier1/10;
		*/
		//adcValue=S_READ_ADC(3);
		
		//shwoSegment(COValue);
		//shwoSegment(COValue*PPM(temperatur/10));
		
		
		
		//	VAmplifier1=(((Amplifier1*(VDD/4095))/gainAmplifier1*1000)/15)*1000;
		//  COValue=VAmplifier1*slope;
		//	shwoSegment(temperatur/10);
		//	shwoSegment(COValue * PPM(temperatur/10));
		
	
	
		
		
		
		
		
	

		
	

	
	
