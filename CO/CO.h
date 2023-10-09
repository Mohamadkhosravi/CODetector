#include "BA45F5240.h"
#include "ADC.h" 
#include "NTC.h" 


#define gainAmplifier1 7.666666666666667  //gainAmplifier1=1+(200k/15k)
#define RSHANT 15 //15k
#define slope 0.04 //m = y2-y1/x2-x1

int ReadCO(float VCC,unsigned int ADC,unsigned short int temperatur);