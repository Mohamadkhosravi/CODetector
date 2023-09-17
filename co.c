#include "BA45F5240.h"
#include "ADC.h" 
#include "NTC.h" 
#include "sevenSegment3DigitComplex.h"
#include "systemClock.h"
#include "GPIO.h"
#include "EEPROM.h"
#include <stdint.h>
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
int my_E2 = 0;
	
void OPAMPset (void);
int cunter=0;
char i;


	
	void main()
	{
	

	
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
		
	
						
	/*			 
    /*	Bit 3~2 INT1S1~INT1S0: Interrupt edge control for INT1 pin
				00: Disable
				01: Rising edge
				10: Falling edge
				11: Rising and falling edges
				Note: For the BA45F5240-2 device, the INT1 external input pin is unavailable, so
				these bits should be fixed at “00”.
				Bit 1~0 INT0S1~INT0S0: Interrupt edge control for INT0 pin
				00: Disable
				01: Rising edge
				10: Falling edge
				11: Rising and falling edges
				Note: For the BA45F5240-2 device, the INT0 external input pin is unavailable, so
				these bits should be fixed at “00
				*/
				_int1s0 =0;
				_int1s1 =1;
				/*
				INT1E: INT1 interrupt control
				0: Disable
				1: Enable
				*/
				_int1e=0;
				/*
				INT1F: INT1 interrupt request flag
				0: No request
				1: Interrupt request
				
				*/
				_int1f=0;
			  _int1e=1;
				
		
		
		
	
			
				CONFIGH_SEG3=INPUT;
				CONFIGH_SEG1=OUTPUT;
				CONFIGH_SEG4=OUTPUT;
				_papu4=1;
		    	_pawu4=1;

		
				if(_pa4 ==1 )	
				{
				CONFIGH_SEG1=OUTPUT;
				CONFIGH_SEG4=OUTPUT;
				SEG1=0;
				SEG4=1;	
				GCC_DELAY(1000);
				}
				else{ 
				CONFIGH_SEG1=INPUT;
				CONFIGH_SEG4=INPUT;
				SEG1=0;
				SEG4=0;
					GCC_DELAY(1000);
					}
		
		
		
		
		
		
		
		
		
		my_E++;

		
		while(1){
			
			_clrwdt();
			
			while(1){
			
			
			
			
		
		
				
				
				
				
				
				
				
				
				
				
				
				
				
				if(_to==0)
				{
				 my_E=0;	
				}
					
			
			
			
			
			
			
			
			
			
				_clrwdt();
				
				cunter++;
			
		    	shwoSegment(22);
			
			if(cunter>100) break;
			}
			cunter=0;
			
			_halt();
			
	
		}
	

	
	
	
	
	
		
		_clrwdt();
		
		//Low Frequency oscillator control when CPU is switched off Disable
	//	_fsiden=0;
	
	
	}
