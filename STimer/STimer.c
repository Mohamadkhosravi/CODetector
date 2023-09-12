#include"STimer.h"

void STimerInit(void){

		
	/*********************
	STPAU: STM Counter Pause Control
	0: Run
	1: Pause
	*/
	_stpau=0;
	
	/********************
	STCK2~STCK0: Select STM Counter Clock
	000: fSYS/4
	001: fSYS
	010: fH/16
	011: fH/64
	100: fSUB
	101: fSUB
	110: STCK rising edge clock
	111: STCK falling edge clock
	*/
	_stck0=0;
	_stck1=0;
	_stck2=0;
	
	/*
	STON: STM Counter On/Off Control
	0: Off
	1: On
	This bit controls the overall on/off function of the STM
	*/
	_ston =1;
	
	/*		
	STRP2~STRP0: STM CCRP 3-bit register, compared with the STM counter bit 9~bit 7
	Comparator P Match Period =
	000: 1024 STM clocks
	001: 128 STM clocks
	010: 256 STM clocks
	011: 384 STM clocks
	100: 512 STM clocks
	101: 640 STM clocks
	110: 768 STM clocks
	111: 896 STM clocks
	*/		
	_strp0=0;
	_strp1=0;
	_strp2=0;
	
	#ifdef  _TIMER_COUNTER_MODE
		/*
		STM1~STM0: Select STM Operating Mode
		00: Compare Match Output Mode
		01: Capture Input Mode
		10: PWM Output Mode or Single Pulse Output Mode
		11: Timer/Counter Mode
		
		*/	
		_stm0=1;
		_stm1=1;
		/*
		STIO1~STIO0: Select STM External Pins Function
		Compare Match Output Mode
		STIO1~STIO0: Select STM External Pins Function
		Compare Match Output Mode
		00: No change
		01: Output low
		10: Output high
		11: Toggle output
		...	
		*/
		_stio0=0;
		_stio1=0;
			
	#endif

	#ifdef COMPARE_MATCH_OUTPUT_MODE
		/*
		STM1~STM0: Select STM Operating Mode
		00: Compare Match Output Mode
		01: Capture Input Mode
		10: PWM Output Mode or Single Pulse Output Mode
		11: Timer/Counter Mode
		*/	
		
		_stm0=0;
		_stm1=0;
		
		/*
		STIO1~STIO0: Select STM External Pins Function
		Compare Match Output Mode
		STIO1~STIO0: Select STM External Pins Function
		Compare Match Output Mode
		00: No change
		01: Output low
		10: Output high
		11: Toggle output
		...	
		*/
		
		_stio0=0;
		_stio1=0;
		
		/*
		STOC: STP Output Control
		Compare Match Output Mode
		0: Initial low
		1: Initial high
		*/
		_stoc =1;
		
		/*	STPOL: STP Output Polarity Control
		0: Non-invert
		1: Invert
	    */
	    
		_stpol =0;
		
		/*		
		STDPX: STM PWM Duty/Period Control
		0: CCRP – period; CCRA – duty
		1: CCRP – duty; CCRA – perio*d
		*/
		
		_stdpx=1;		
		
				
		/*
		STCCLR: STM Counter Clear Condition Selection
		0: Comparator P match
		1: Comparator A match
		This bit is used to select the
		*/
		_stcclr = 1;		
		/*
		D7~D0: STM CCRA Low Byte Register bit 7 ~ bit 0
		STM 10-bit CCRA bit 7 ~ bit 0
		*/
		_stmal=0b11111111;
		
		/*
		D9~D8: STM CCRA High Byte Register bit 1 ~ bit 0
		STM 10-bit CCRA bit 9 ~ bit 8
		*/
		
		_stmah=0b11;
		
		


	 _clrwdt();
		
#endif
		
	
	
	
	
	
	
	
	
	
	
	
	
	
}
int readSTimer(void){
	 _clrwdt();
		
	return((_stmdl)|(_stmdh<<8));
		
}