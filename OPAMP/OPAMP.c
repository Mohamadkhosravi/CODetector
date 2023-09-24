
#include"OPAMP.h"





void OPAMPset (void){
	FT=1;


//SD OPAMP0 enable
_sda0en=1;


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



	
}



void OPAMPInit(void){


//PA1 = A1PI
_pas02=1;
_pas03=1;



//OPAMP AFE

//AFE SW
_sds0=0;
_sds1=0;
_sds2=1;////////
_sds3=0;////////
_sds4=1;
//01: AC coupling mode
_sds5=0;
_sds6=0;

_sda0ofm=0;
_sda1ofm=0;

//R1 resistance control
_sdpgac0=0b00000001;  //*100k


//5-0: R2 resistance control ?100k
//7-6: R3 resistance control *10k+10k
_sdpgac1=0b11000001;

//OPAMP0 bandwidth control 00: 5kHz
_sda0bw0=0;
_sda0bw1=0;

//OPAMP0 bandwidth control 00: 5kHz
_sda1bw0=0;
_sda1bw1=0;


//SD OPAMP0 enable or disable control
_sda0en=1;


_sda0ofm=0;
_sda0rsp=0;

_sda1ofm=0;
_sda1rsp=0;



//OPAMP clbrashen for onse
if (FT==0){  
OPAMPset ();
}



}