#include "BA45F5240.h"
#include "ADC.h" 
#include "NTC.h" 
#include "sevenSegment3DigitComplex.h"
#include "systemClock.h"
#include "GPIO.h"
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

#define MAXppm 1000
#define slope 0.0275 //m = y2-y1/x2-x1

#define ConstA 0.000000056
#define ConstB 0.000007217
#define ConstC 0.000202579
#define ConstD 0.0133869
#define PPM(x)((ConstB*(x*x*x))+(ConstC*(x*x))+(ConstD*(x))+0.7)


#define I(VOut)(VOut+((RS+(RF)/RS*(RF))*((R2/R3)+1)))
//temperatur  =  1.20*(4095.000/ S_READ_ADC(4));
#define VBattery(ADC_BAT)( 1.20*(4095.000/ ADC_BAT))

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
float VDD=0;
bit bat_low;
int V_ref;




//float V_ntc;
bit falt;

	
	
void OPAMPset (void);
//int ADC ( char pin);


float COValue =0.0;
float temperatur=0.0;
float Amplifier1=0.0;
float tempAmplifier1=0.0;
float VAmplifier1=0.0;
float tempAmplifier2=0.0;
float Amplifier2=0.0;
float adcValue=0.0;
float vss;
int cunter=0;
// float tm =0.0;
int i;





void main()
{
	
	ClockInit();
	GPIOInit();
	GPIOToGNDCurentInit();
	OPAMPInit();
	S_ADC_Init();


	
	do
	{
	
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
		
		//	V_ref=0;
		GCC_DELAY(1000);
		
		S_ADC_Init();
		_vbgren=1;
		
		
		
		_sda0en=1;
		_sda1en=1; 

	while(1){
		
		NTCToGND=1;
		//temperatur= temperature(S_READ_ADC(1),3.3);
		//shwoSegment((1.20*(4095/ VB_ADC))*100);  
		// vbgren enable
		
		_vbgren=1;
		
		float VB_ADC=0;
		//  temperatur = 0;
		
		//RT = ((R1 * RB * (RS + R2) * (I - vout - 1)) / ((I - vout - 1) - RB * (RS + R2))) - R1
		
	VDD = VBattery(S_READ_ADC(4));
		//shwoSegment(VDD*10);
		
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
		/*	
		tempAmplifier2=0;
		Amplifier2=0;
	
		for (i=0;i<10;i++)
		{
			Amplifier2=S_READ_ADC(6);
			tempAmplifier2=tempAmplifier2+Amplifier2;
		
		}
		Amplifier2=tempAmplifier2/10;
		COValue=(((Amplifier2*(VDD/4095)/(AVAmplifier1*AVAmplifier2))/slope )*100000);
		// shwoSegment(COValue*10);
		*/
		//temperatur= temperature(S_READ_ADC(1),3.3);
		
		while(1){
		//	Amplifier1=S_READ_ADC(5);
			_clrwdt();
			
			
			
			
			
			tempAmplifier1=0;
			Amplifier1=0;
			
			for (i=0;i<10;i++)
			{
				Amplifier1=S_READ_ADC(5);
				tempAmplifier1=tempAmplifier1+Amplifier1;
				
			}
			Amplifier1=tempAmplifier1/10;
		
			
		/*
			tempAmplifier2=0;
			Amplifier2=0;
			
			for (i=0;i<10;i++)
			{
				Amplifier2=S_READ_ADC(6);
				tempAmplifier2=tempAmplifier2+Amplifier2;
			
			}
			Amplifier2=tempAmplifier2/10;
			
		
			//COValue=(((Amplifier1*(VDD/4095)/(AVAmplifier1))/slope )*100000);
		*/
		  //adcValue=S_READ_ADC(3);
		
		    //shwoSegment(COValue);
		    //shwoSegment(COValue*PPM(temperatur/10));
		
			
			 VAmplifier1=(((Amplifier1*(VDD/4095))/gainAmplifier1*1000)/15)*1000;
			 COValue=VAmplifier1*slope;
			 shwoSegment(COValue);
			
			
		//	cunter++;
		
		if(cunter>100)break;
		}
		cunter=0;
		
	    VDD=0;
	//-------------------calculate Temperature-----------------------------<<<
	}



//----------test but-----------
/*
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
	*/
//----------test but-----------




/*
//----------bat chek-----------

if (VDD<3.00){
	bat_low=1;
	}else{
		bat_low=0;
		}
*/	
//----------bat chek-----------


/*
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
*/

/*	
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

*/


//----------co alarm chek-----------	
/*	
if (ppm>=co_set){
	co=1;
	LED_R=!LED_R;
	_clrwdt();
	}else{
		co=0;
		LED_R=0;
		}


//while(1){}
*/
	}while(co);

//----------co alarm chek-----------	



	//PA7~PA0 wake-up function control
	_pawu=0b00010000;
	
	_clrwdt();
	
	//Low Frequency oscillator control when CPU is switched off Disable
	_fsiden=0;


}



	


