#include "BA45F5240.h"

#include <math.h>
#define pA_ppm 5212
#define co_set 1205 //ppm
#include "ADC.h" 
#include "NTC.h" 
#include "sevenSegment3DigitComplex.h"
#include "GPIO.h" 
#include "OPAMP.h" 
#include "systemClock.h" 
//ADC


//#define VBAT(ADC_BAT)( (VCC/ADCNumerOfbits) * ADC_NTC )

#define VBattery(ADC_BAT)(1.20*(4095/ ADC_BAT)*100)

//test
char test_tm;
bit test;


//ISINK 0,1
#define NTC_GND _isgs0
#define LED_G 	_isgs1



//BUZ
int buz_delay;


//OPAMP 
bit FT=0;	//opamp ofset callbration
int V_op0;
int V_op1;
char VA0OS,VA0OS1,VA0OS2;
char VA1OS,VA1OS1,VA1OS2;
bit opamp0,opamp1;
	//OPAMP EN
	#define OP0EN _sda0en
	#define OP1EN _sda1en
	

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
	
//System clock selection fsys  =fSUB
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

	
//System clock selection fsys  =f HIRC
_cks0=0;
_cks1=0;
_cks2=0;

//********************************================================================================================================================================================

	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Sink Current Generator
	
	//Sink current generator enable control
	_isgen=1;
	
	//Sink current generator control for ISINK0 pin
	//Current value (mA) = 50 + 10 × (ISGDATA0[4:0])
	_isgdata0=0b00000000;
	
	//Sink current generator control for ISINK1 pin
	//Current value (mA) = 50 + 5 × (ISGDATA1[4:0])
	_isgdata1=0b00000000;
	
	
	
	//Enable/Disable ISINK0 pin sink current control
	_isgs0=0;
	
	//Enable/Disable ISINK1 pin sink current control
	_isgs1=0;

/////////////////////////////////////////////////////////////////////////////////////////////////////

//OPAMP AFE
//AFE SW
/*
_sds0=0;
_sds1=0;
_sds2=0;////////
_sds3=0;////////
_sds4=1;
_sds5=0;
_sda0ofm=0;
*/

_sds0=0;
_sds1=0;
_sds2=0;////////
_sds3=1;////////
_sds4=0;
_sds5=0;
_sds6=1;


//R1 resistance control
_sdpgac0=0b00000001;

//5-0: R2 resistance control ×100k
//7-6: R3 resistance control *10k+10k
_sdpgac1=0b11000001;

//OPAMP0 bandwidth control 00: 5kHz
_sda0bw0=0;
_sda0bw1=0;

//OPAMP0 bandwidth control 00: 5kHz
_sda1bw0=0;
_sda1bw1=0;
//************************************
//SD OPAMP0 enable or disable control
_sda0en=1;

//********************************
//input opamp 0 switch
_sda0ofm=0;
_sda0rsp=0;

//input opamp 1 switch
_sda1ofm=0;
_sda1rsp=0;



//OPAMP clbrashen for onse
if (FT==0){  
OPAMPset ();
}


//SD OPAMP0 disable control
_sda0en=0;

//SD OPAMP1 disable control
_sda1en=0;




float temperatur=0;

float temp=0;
int i=0;
unsigned int cunter=0;

float VB_ADC=0;


//********************************================================================================================================================================================

/////////////////////////////////////////////////////////////////////////////////////////////////////////



	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
//**************************************************************
	
//----------------------------------------------------------------------------------------------------------

do{

LED_G=1;

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

//enable OPAMP
OP0EN=1;
//OP1EN=1;

NTC_GND=1;



GCC_DELAY(1000);



//V_op0=Vdd*V_op0/4096;
//V_op1=Vdd*V_op1/4096;

ppm=pA_ppm / V_op0 ;


//---------------------ADC read-------------------------<<<


LED_G=0;
//-------------------calculate Temperature--------------------------->>>


	//V_op0=29;
	ppm=19.2;

    temp=0;
	Vdd=0;
	V_ref=0;
	GCC_DELAY(100000);
	
	S_ADC_Init();
  _vbgren=1;
  
  
  
  
  
while(1){

temperatur= temperature(S_READ_ADC(1),3.3);
 //shwoSegment((1.20*(4095/ VB_ADC))*100);  
// vbgren enable


  

	while(1){

	_clrwdt();
     //tm  = S_READ_ADC(5);
     
    shwoSegment( temperatur);
     
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
		LED_G=1;
		GCC_DELAY(10000); 
		LED_G=0;
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


void OPAMPset (void){


	FT=1;


//Operational Amplifier0 Input Offset Calibration


//Step1
_sda0ofm=1;
_sda0rsp=1;


//Step2
_sda0of0=0;
_sda0of1=0;
_sda0of2=0;
_sda0of3=0;
_sda0of4=0;
_sda0of5=0;

opamp0=_sda0o;

//Step3

	while (opamp0==_sda0o){
		if (_sda0vos==0b11111111) break;
		_sda0vos=_sda0vos+1;
	}

VA0OS1=_sda0of0<<0 || _sda0of1<<1 || _sda0of2<<2 || _sda0of3<<3 || _sda0of4<<4 || _sda0of5<<5 ;

//Step4
_sda0of0=0;
_sda0of1=0;
_sda0of2=0;
_sda0of3=0;
_sda0of4=0;
_sda0of5=0;

opamp0=_sda0o;


//Step5
VA0OS1=_sda0vos && 0b00111111;

	while (opamp0==_sda0o){
		_sda0vos=_sda0vos-1;
		if (_sda0vos==0b11000000) break;
	}

VA0OS2=_sda0of0<<0 || _sda0of1<<1 || _sda0of2<<2 || _sda0of3<<3 || _sda0of4<<4 || _sda0of5<<5 ;


//Step6
VA0OS=(VA0OS1+VA0OS2)/2;
_sda0vos=0b00111111 && VA0OS;



//SD OPAMP0 disable
_sda0en=0;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////



//SD OPAMP1 enable or disable control
_sda1en=1;


//Operational Amplifier1 Input Offset Calibration


//Step1
_sda1ofm=1;
_sda1rsp=1;


//Step2
_sda1of0=0;
_sda1of1=0;
_sda1of2=0;
_sda1of3=0;
_sda1of4=0;
_sda1of5=0;

opamp1=_sda1o;

//Step3

	while (opamp1==_sda1o){
	_sda1vos=_sda1vos+1;
	VA0OS1=_sda1vos && 0b00111111;
	if (VA1OS1>=0b00111111) break;
	}

VA1OS1=_sda1of0<<0 || _sda1of1<<1 || _sda1of2<<2 || _sda1of3<<3 || _sda1of4<<4 || _sda1of5<<5 ;

//Step4
_sda1of0=1;
_sda1of1=1;
_sda1of2=1;
_sda1of3=1;
_sda1of4=1;
_sda1of5=1;

opamp1=_sda1o;


//Step5
VA1OS1=_sda1vos && 0b00111111;

	while (opamp1==_sda1o){
	_sda1vos=_sda1vos-1;
	VA1OS2=_sda1vos && 0b00111111;
	if (VA1OS2<=0b00000000) break;
	}

VA1OS2=_sda1of0<<0 || _sda1of1<<1 || _sda1of2<<2 || _sda1of3<<3 || _sda1of4<<4 || _sda1of5<<5 ;


//Step6
VA1OS=(VA0OS1+VA1OS2)/2;
_sda1vos=0b00111111 && VA1OS;



//SD OPAMP1 disable
_sda1en=0;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Analog to Digital Converter



//A/D converter data format select  1: A/D converter data format?SADOH=D[11:8]; SADOL=D[7:0]
_adrfs=1;

//A/D converter reference voltage select  Internal A/D converter power, VDD
_savrs0=1;
_savrs1=0;


//A/D conversion clock source select  =fSYS
_sacks0=0;
_sacks1=0;
_sacks2=0;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Sink Current Generator

//Sink current generator enable control
_isgen=1;

//Sink current generator control for ISINK0 pin
//Current value (mA) = 50 + 10 × (ISGDATA0[4:0])
_isgdata0=0b00000000;

//Sink current generator control for ISINK1 pin
//Current value (mA) = 50 + 5 × (ISGDATA1[4:0])
_isgdata1=0b00000000;



//Enable/Disable ISINK0 pin sink current control
_isgs0=0;

//Enable/Disable ISINK1 pin sink current control
_isgs1=0;























/*


	FT=1;
	
	//Operational Amplifier0 Input Offset Calibration
	//SD OPAMP0 enable
//**************
	_sda0en=1;



	//Step1
	_sda0ofm=1;
	_sda0rsp=1;
	
	
	//Step2
	_sda0of0=0;
	_sda0of1=0;
	_sda0of2=0;
	_sda0of3=0;
	_sda0of4=0;
	_sda0of5=0;
	
	opamp0=_sda0o;
	
	//Step3
//_pltc0out

	while (opamp0==_sda0o){
		if (_sda0vos==0b11111111) break;
		_sda0vos=_sda0vos+1;
	}

	VA0OS1=_sda0of0<<0 || _sda0of1<<1 || _sda0of2<<2 || _sda0of3<<3 || _sda0of4<<4 || _sda0of5<<5 ;
	
	//Step4
	_sda0of0=1;
	_sda0of1=1;
	_sda0of2=1;
	_sda0of3=1;
	_sda0of4=1;
	_sda0of5=1;
	
	opamp0=_sda0o;
	
	
	//Step5
	VA0OS1=_sda0vos && 0b00111111;
	
		while (opamp0==_sda0o){
			_sda0vos=_sda0vos-1;
			if (_sda0vos==0b11000000) break;
		}
	
	VA0OS2=_sda0of0<<0 || _sda0of1<<1 || _sda0of2<<2 || _sda0of3<<3 || _sda0of4<<4 || _sda0of5<<5 ;
	
	
	//Step6
	VA0OS=(VA0OS1+VA0OS2)/2;
	_sda0vos=0b00111111 && VA0OS;
	
	
	
	//SD OPAMP0 disable
	_sda0en=0;
	
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
	
	//SD OPAMP1 enable or disable control
	_sda1en=1;
	
	
	//Operational Amplifier1 Input Offset Calibration
	
	
	//Step1
	_sda1ofm=1;
	_sda1rsp=1;
	
	
	//Step2
	_sda1of0=0;
	_sda1of1=0;
	_sda1of2=0;
	_sda1of3=0;
	_sda1of4=0;
	_sda1of5=0;
	
	opamp1=_sda1o;
	
	//Step3

	while (opamp1==_sda1o){
		_sda1vos=_sda1vos+1;
		VA0OS1=_sda1vos && 0b00111111;
		if (VA1OS1>=0b00111111) break;
	}

	VA1OS1=_sda1of0<<0 || _sda1of1<<1 || _sda1of2<<2 || _sda1of3<<3 || _sda1of4<<4 || _sda1of5<<5 ;
	
	//Step4
	_sda1of0=1;
	_sda1of1=1;
	_sda1of2=1;
	_sda1of3=1;
	_sda1of4=1;
	_sda1of5=1;
	
	opamp1=_sda1o;

	//Step5
	VA1OS1=_sda1vos && 0b00111111;

	while (opamp1==_sda1o){
		_sda1vos=_sda1vos-1;
		VA1OS2=_sda1vos && 0b00111111;
		if (VA1OS2<=0b00000000) break;
	}

	VA1OS2=_sda1of0<<0 || _sda1of1<<1 || _sda1of2<<2 || _sda1of3<<3 || _sda1of4<<4 || _sda1of5<<5 ;
	
	
	//Step6
	VA1OS=(VA0OS1+VA1OS2)/2;
	_sda1vos=0b00111111 && VA1OS;
	
	
	
	//SD OPAMP1 disable
	_sda1en=0;
	
*/

	
}
