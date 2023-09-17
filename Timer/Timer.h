
#ifndef STM_H
#define STM_H

#include "BA45F5240.h"

void timerBaseInit(void);

void STimerInit(void);
int readSTimer(void);

//#define _TIMER_COUNTER_MODE
#define COMPARE_MATCH_OUTPUT_MODE

#endif
