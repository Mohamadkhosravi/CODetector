#ifndef BUTTON_H
#define BUTTON_H

#include "BA45F5240.h"












#define SET 0
#define RESET 1

#define DEBOUNCE_THRESHOLD 2
#define LONG_PRESS_DELAY_MS 2

// buttonState = BUTTON_STATE_IDLE;
static int lastPressTime = 0;
static int pressCount = 0;
static int debounceCounter = 0;













void buttonInit(void);
void buttonUpdate(void);
//buttonStatus buttonGetState(void);

#endif /* BUTTON_H */
