
#ifndef TM_H
#define TM_H

#include "BA45F5240.h"

void timerBaseInit(void);

void STimerInit(void);
void PTimerInit(void);
int readSTimer(void);
void PWMSeter(int status);
//#define _TIMER_COUNTER_MODE
#define COMPARE_MATCH_OUTPUT_MODE



#endif
