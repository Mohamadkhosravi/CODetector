#include "BA45F5240.h"


unsigned int debounceCounter=0;
char keyState=0;
char pressLockFlag =2;
char pressFlag=0;
unsigned int keyCounter=0;

 typedef enum {

	IDLE,
	SINGLE,
	DOUBLE,
	LONGPRESS,
	NONPRESS

}buttonType;
#define KEY_PIN _pa4
#define SET 0
#define RESET 1
#define DEBOUNCE_THRESHOLD 2000
#define PRESS_STATE_TIMOUT 500

#define LONGPRESS_TIMOUT 1000


buttonType key(void);