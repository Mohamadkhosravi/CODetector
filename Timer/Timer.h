
#include "BA45F5240.h"
#define TM_H
#ifdef TM_H


#define PTIMER
	
	
	
	#ifdef BASETIMER 
	
		void timerBaseInit(void);
		
	#endif
	
	#ifdef  STIMER
	
	  //#define _TIMER_COUNTER_MODE
	   #define COMPARE_MATCH_OUTPUT_MODE
		void STimerInit(void);
		int readSTimer(void);
		
	#endif	
	
	
	#ifdef PTIMER
			
		void PTimerInit(void);
		void PWMSeter(char status);
	
	#endif
	


#endif
