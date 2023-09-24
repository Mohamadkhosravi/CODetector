
#ifndef SEVEN_SEGMENT_H
#define SEVEN_SEGMENT_H

	#include "BA45F5240.h"

	#define DELAY_CONFIGH_SEG 1
	#define DELAY_SEG 1
	
	
	#define CONFIGH_SEG1 _pbc2
	#define CONFIGH_SEG2 _pbc1
	#define CONFIGH_SEG3 _pac4
	#define CONFIGH_SEG4 _pac0
	#define CONFIGH_SEG5 _pac2
	#define CONFIGH_SEG6 _pbc3
	
	
	#define OUTPUT 0
	#define INPUT  1
	

	//7SEG
	#define SEG1 _pb2// SEG1
	#define SEG2 _pb1// SEG2
	#define SEG3 _pa4// SEG3
	#define SEG4 _pa0// SEG4
	#define SEG5 _pa2// SEG5
	#define SEG6 _pb3// SEG6
	
	
	
	
	
	
	void errorSeg(void);
	void errorSeg1(void);
	
	void ziroDigit1(void);
	void ziroDigit2(void);
	void ziroDigit3(void);
	
	void oneDigit1(void);
	void oneDigit2(void);
	void oneDigit3(void);
	
	void towDigit1(void);
	void towDigit2(void);
	void towDigit3(void);
	
	void threeDigit1(void);
	void threeDigit2(void);
	void threeDigit3(void);
	
	void fourDigit1(void);
	void fourDigit2(void);
	void fourDigit3(void);
	
	void fiveDigit1(void);
	void fiveDigit2(void);
	void fiveDigit3(void);
	
	void sixDigit1(void);
	void sixDigit2(void);
	void sixDigit3(void);
	
	void sevenDigit1(void);
	void sevenDigit2(void);
	void sevenDigit3(void);
	
	void eightDigit1(void);
	void eightDigit2(void);
	void eightDigit3(void);
	
	void nineDigit1(void);
	void nineDigit2(void);
	void nineDigit3(void);
	
	int length(int number);
	int shwoSegment(int number);
	void clearSegment(void);

#endif