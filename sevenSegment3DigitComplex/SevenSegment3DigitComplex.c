
#include<sevenSegment3DigitComplex.h>




void errorSeg(void){
	//clearSegment();
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG1=0;
	SEG2=1;
	SEG5=1;
	SEG6=1;
	GCC_DELAY(1000);
    clearSegment();
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	SEG2=0;
	SEG3=1;
	SEG4=1;
	GCC_DELAY(1000);
	clearSegment();
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG6=OUTPUT	;
	SEG1=1;
	SEG2=0;
	SEG6=0;	
	GCC_DELAY(1000);
	clearSegment();
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG5=OUTPUT	;
	SEG2=0;
	SEG5=1;
    GCC_DELAY(1000);
    //=================== o
 
}




void error1Seg(void){

	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG1=0;
	SEG2=1;
	SEG5=1;
	SEG6=1;
	GCC_DELAY(1000);
    clearSegment();
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	SEG2=0;
	SEG3=1;
	SEG4=1;
	GCC_DELAY(1000);
	clearSegment();
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG6=OUTPUT	;
	SEG1=1;
	SEG2=0;
	SEG6=0;	
	GCC_DELAY(1000);
	clearSegment();
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG5=OUTPUT	;
	SEG2=0;
	SEG5=1;
    GCC_DELAY(1000);
    //=================== o
    clearSegment();
		
		
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	 CONFIGH_SEG5=OUTPUT;
	 SEG2=1;
	 SEG4=0;
	 SEG5=0;
	 GCC_DELAY(1000);
}


void ziroDigit1(void){
	

		
	
	
	GCC_DELAY(1000);
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5 = OUTPUT;
	CONFIGH_SEG6 = OUTPUT;
	SEG1=0;
	SEG2=1;
	SEG3=1;
	SEG4=1;
	SEG5=1;
	SEG6=1;
	
	GCC_DELAY(1000);
	clearSegment();
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	SEG4=0;
	SEG2=0;
	GCC_DELAY(1000);
	
	clearSegment();
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	SEG2=0;
	SEG3=1;
	GCC_DELAY(1000);	
			
}
void ziroDigit2(void){
	
	
		
		
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT; 
	CONFIGH_SEG3=OUTPUT; 
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG1=1;
	SEG2=0;
	SEG3=0;
	SEG4=0;
	SEG5=0;	
	SEG6=0;
	GCC_DELAY(1000);
	clearSegment();
	CONFIGH_SEG6=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	SEG6=0;
	SEG2=0;
	GCC_DELAY(1000);
	
	clearSegment();
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	SEG2=0;
	SEG5=1;
	GCC_DELAY(1000);



	
	
}
void ziroDigit3(void){

		
		
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG2=1;
	SEG3=0; 
	SEG4=0;
	SEG5=0;
	SEG6=0;
	GCC_DELAY(1000);
	clearSegment();
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	SEG3=1; 
	SEG4=0;
	SEG5=0;
	GCC_DELAY(1000);
	clearSegment();
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG3=0; 
	SEG6=0;
	GCC_DELAY(1000);
	 
 	
}
 
void oneDigit1(void){

		
	
	
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	SEG1=0;
	SEG3=1;
	SEG4=1;
	GCC_DELAY(1000);
}
void oneDigit2(void) {

			
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG3=OUTPUT; 
	CONFIGH_SEG4=OUTPUT;
	SEG1=1;
	SEG3=0;
	SEG4=0;
	GCC_DELAY(1000);
  
 }  
void oneDigit3(void){
	
		
		
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	 CONFIGH_SEG5=OUTPUT;
	 SEG2=1;
	 SEG4=0;
	 SEG5=0;
	 GCC_DELAY(1000);
	 
	 
	clearSegment();
	 
	 
}

void towDigit1(void){

		
			
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG1=0;
	SEG2=1;
	SEG3=1;
	SEG5=1;
	SEG6=1;
	
	GCC_DELAY(1000);
	
	clearSegment();
	
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	SEG2=0;
	SEG4=1;
	
	GCC_DELAY(1000);
	 
}
void towDigit2(void){
		
			
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	
	SEG1=1;
	SEG2=0;
	SEG3=0;
	SEG5=0;
	SEG6=0;
	
	GCC_DELAY(1000);
	
	clearSegment();
	
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG2=0;
	SEG6=1;
	
	GCC_DELAY(1000);	
	
}
void towDigit3(void){
	
	
		
	
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG2=1;
	SEG3=0;
	SEG4=0;
	SEG5=0;
	SEG6=0;
	
	GCC_DELAY(1000);
	
	clearSegment();
	
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	
	SEG3=1;
	SEG4=0;
	SEG6=0;
	
	GCC_DELAY(1000);	
	
}

void threeDigit1(void){

		
		
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	SEG1=0;
	SEG2=1;
	SEG3=1;
	SEG4=1;
	SEG5=1;	
	
	GCC_DELAY(1000);
	clearSegment();
	
	CONFIGH_SEG1 = INPUT;
	CONFIGH_SEG2 = OUTPUT;
	CONFIGH_SEG3 = INPUT;
	CONFIGH_SEG4 = OUTPUT;
	CONFIGH_SEG5 = INPUT;
	CONFIGH_SEG6 = INPUT;
	SEG4=1;
	SEG2=0;
	GCC_DELAY(1000);
}
void threeDigit2(void){
	
		
		
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT; 
	CONFIGH_SEG3=OUTPUT; 
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	SEG1=1;
	SEG2=0;
	SEG3=0;
	SEG4=0;
	SEG5=0;
	GCC_DELAY(1000);
	clearSegment();
	
	
	CONFIGH_SEG2=OUTPUT; 
	CONFIGH_SEG6=OUTPUT;
	SEG2=0;
	SEG6=1;
  GCC_DELAY(1000);
	
}
void threeDigit3(void){

		
		

	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT; 
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG2=1;
	SEG3=0;
	SEG4=0;
	SEG5=0;
	SEG6=0;	
    GCC_DELAY(1000);
	clearSegment();
	CONFIGH_SEG3=OUTPUT; 	
	CONFIGH_SEG6=OUTPUT;
	SEG3=1;
	SEG6=0;
GCC_DELAY(1000);	
		
}

void fourDigit1(void){

		
		
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	SEG1=0;
	SEG3=1;
	SEG4=1;	
	
	GCC_DELAY(1000);
	clearSegment();
	
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	SEG2=0;
	SEG3=1;
	SEG4=1;
	GCC_DELAY(1000);

}
void fourDigit2(void){

		
		
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG3=OUTPUT; 
	CONFIGH_SEG4=OUTPUT;
	SEG1=1;
	SEG3=0;
	SEG4=0;

	GCC_DELAY(1000);
	clearSegment();
	
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG5=OUTPUT; 
	CONFIGH_SEG6=OUTPUT;
	SEG2=0;
	SEG5=1;
	SEG6=1;
	GCC_DELAY(1000);	
	
}
void fourDigit3(void){

		
		
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	SEG2=1;
	SEG4=0;
	SEG5=0;
	GCC_DELAY(1000);
	clearSegment();
	
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG3=1;
	SEG5=0;
	SEG6=0;
	GCC_DELAY(1000);
}

void fiveDigit1(void){

		
		
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	SEG1=0;
	SEG2=1;
	SEG4=1;
	SEG5=1;
	GCC_DELAY(1000);
	clearSegment();	
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	SEG2=0;
	SEG3=1;
	SEG4=1;
	GCC_DELAY(1000);
	
	
}
void fiveDigit2(void){
	
		
		
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	SEG1=1;
	SEG2=0;
	SEG4=0;
	SEG5=0;
	GCC_DELAY(1000);
	clearSegment();
	
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG5=OUTPUT; 
	CONFIGH_SEG6=OUTPUT;
	SEG2=0;
	SEG5=1;
	SEG6=1;
	GCC_DELAY(1000);	
	
	
}
void fiveDigit3(void){

		
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG2=1;
	SEG3=0;
	SEG5=0;
	SEG6=0;
	GCC_DELAY(1000);
	clearSegment();
	
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG3=1;
	SEG5=0;
	SEG6=0;
	GCC_DELAY(1000);
	
	
}

void sixDigit1(void){
		
		
    CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG1=0;
	SEG2=1;
	SEG4=1;
	SEG5=1;
	SEG6=1;
	GCC_DELAY(1000);
	clearSegment();	
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	SEG2=0;
	SEG3=1;
	SEG4=1;
	GCC_DELAY(1000);	
	
	
}
void sixDigit2(void){

		
		
    CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG1=1;
	SEG2=0;
	SEG4=0;
	SEG5=0;
	SEG6=0;
	GCC_DELAY(1000);
	clearSegment();
	
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG5=OUTPUT; 
	CONFIGH_SEG6=OUTPUT;
	SEG2=0;
	SEG5=1;
	SEG6=1;
	GCC_DELAY(1000);		
	
}
void sixDigit3(void){

		
		
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG2=1;
	SEG3=0;
	SEG5=0;
	SEG6=0;
	GCC_DELAY(1000);
	clearSegment();
	
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG3=1;
	SEG4=0;
	SEG5=0;
	SEG6=0;
	GCC_DELAY(1000);	
}

void sevenDigit1(void){
		
		
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	SEG1=0;
	SEG2=1;
	SEG3=1;
	SEG4=1;
	GCC_DELAY(1000);


}
void sevenDigit2(void){

		
		
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT; 
	CONFIGH_SEG3=OUTPUT; 
	CONFIGH_SEG4=OUTPUT;
	
	SEG1=1;
	SEG2=0;
	SEG3=0;
	SEG4=0;
GCC_DELAY(1000);
}
void sevenDigit3(void){

		
		
	 CONFIGH_SEG2=OUTPUT;
	 CONFIGH_SEG3=OUTPUT;
	 CONFIGH_SEG4=OUTPUT;
	 CONFIGH_SEG5=OUTPUT;
	 SEG2=1;
	 SEG3=0; 
	 SEG4=0;
	 SEG5=0;
GCC_DELAY(1000);
}


void eightDigit1(void){

   
	
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
    CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	
		
	SEG1=0;
	SEG2=1;
	SEG3=1;
	SEG4=1;
	SEG5=1;
	SEG6=1;
	
	GCC_DELAY(1000);
		
	clearSegment();
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	SEG2=0;
	SEG3=1;
	
	GCC_DELAY(1000);
	clearSegment();
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	SEG4=1;
	SEG2=0;
	GCC_DELAY(1000);
	
}
void eightDigit2(void){

	
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT; 
	CONFIGH_SEG3=OUTPUT; 
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG1=1;
	SEG2=0;
	SEG3=0;
	SEG4=0;
	SEG5=0;	
	SEG6=0;
	GCC_DELAY(1000);
	clearSegment();
	CONFIGH_SEG6=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	SEG6=1;
	SEG2=0;
	GCC_DELAY(1000);
	
	clearSegment();
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	SEG2=0;
	SEG5=1;
	GCC_DELAY(1000);	
}
void eightDigit3(void){
	

	
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG2=1;
	SEG3=0; 
	SEG4=0;
	SEG5=0;
	SEG6=0;
	GCC_DELAY(1000);
	clearSegment();
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG3=1; 
	SEG4=0;
	SEG5=0;
	SEG6=0;
	GCC_DELAY(1000);

}

void nineDigit1(void){
	
	
	GCC_DELAY(1000);
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5 = OUTPUT;
	SEG1=0;
	SEG2=1;
	SEG3=1;
	SEG4=1;
	SEG5=1;

	
	GCC_DELAY(1000);
		
	clearSegment();
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	SEG2=0;
	SEG3=1;
	
	GCC_DELAY(1000);
	clearSegment();
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	SEG4=1;
	SEG2=0;
	GCC_DELAY(1000);	
}
void nineDigit2(void){
	
	
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG2=OUTPUT; 
	CONFIGH_SEG3=OUTPUT; 
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;

	SEG1=1;
	SEG2=0;
	SEG3=0;
	SEG4=0;
	SEG5=0;	
	
	GCC_DELAY(1000);
	clearSegment();
	
	CONFIGH_SEG6=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	SEG6=1;
	SEG2=0;
	GCC_DELAY(1000);
	
	clearSegment();
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG2=OUTPUT;
	SEG2=0;
	SEG5=1;
	GCC_DELAY(1000);		
}
void nineDigit3(void){ 

	
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG2=1;
	SEG3=0; 
	SEG4=0;
	SEG5=0;
	SEG6=0;
	
	GCC_DELAY(1000);
	clearSegment();
	
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG5=OUTPUT;
	CONFIGH_SEG6=OUTPUT;
	SEG3=1; 
	SEG5=0;
	SEG6=0;
	GCC_DELAY(1000);	
}

int length(int number){
	int cunter=0;
	while(number!=0){
		
		number = number/10;
		cunter++;
	}
	return cunter;

}
 int shwoSegment(int number)
 {

	char lenNumber=0;
	char len=0;
	char powNumber=1;

	int indexDigit=0;
	int digNumber=0;
	int firstNumber;

	if(number==0)
	{
	 ziroDigit1();
	 return 1;	
	}
	

	if(number<0)
	{
	 error1Seg();
	 return 1;	
	}
	
	if(number>999)
	{
	 errorSeg();
	  return 1;	
	}
//	if (lenNumber<1) return -1;//error
	lenNumber =length(number);
	if(lenNumber=2)powNumber=10;
	if(lenNumber=3)powNumber=100;
	for( indexDigit=lenNumber; indexDigit>=0 ; indexDigit--)
//	for( indexDigit=0; indexDigit<=lenNumber; indexDigit++)
	{
	    digNumber = number /powNumber;
		number=number-(digNumber*powNumber);		
	//	if(powNumber<10) return 1;
	
		switch(indexDigit) 
		{
			clearSegment();
		
					
			case 1:
			{
		 
			 	switch(digNumber)
			 	{
			 	
			 		case 0:{clearSegment();ziroDigit3();} break;
			 		case 1:{clearSegment();oneDigit3();}	break;
			 		case 2:{clearSegment();towDigit3();}	break;
			 		case 3:{clearSegment();threeDigit3();}break;
			 		case 4:{clearSegment();fourDigit3();}	break;
			 		case 5:{clearSegment();fiveDigit3();}	break;
			 		case 6:{clearSegment();sixDigit3();}	break;
			 		case 7:{clearSegment();sevenDigit3();}break;
			 		case 8:{clearSegment();eightDigit3();}break;
			 		case 9:{clearSegment();nineDigit3();}	break;
			 	
			 	
				}
				break;
			}

			case 2:
			{
		 
			 	switch(digNumber)
			 	{
			 		case 0:{clearSegment();ziroDigit2(); } break;
			 		case 1:{clearSegment();oneDigit2();  }	break;
			 		case 2:{clearSegment();towDigit2();  }	break;
			 		case 3:{clearSegment();threeDigit2(); }break;
			 		case 4:{clearSegment();fourDigit2();}	break;
			 		case 5:{clearSegment();fiveDigit2(); }	break;
			 		case 6:{clearSegment();sixDigit2(); }	break;
			 		case 7:{clearSegment();sevenDigit2();}break;
			 		case 8:{clearSegment();eightDigit2();}break;
			 		case 9:{clearSegment();nineDigit2(); }	break;
			 	}
				break;
			};
			
			case 3:
			{
		 	    switch(digNumber)
			 	{
			 		case 0:{clearSegment();ziroDigit1();} break;
			 		case 1:{clearSegment();oneDigit1();}	break;
			 		case 2:{clearSegment();towDigit1(); }	break;
			 		case 3:{clearSegment();threeDigit1();}break;
			 		case 4:{clearSegment();fourDigit1();}	break;
			 		case 5:{clearSegment();fiveDigit1();}	break;
			 		case 6:{clearSegment();sixDigit1(); }	break;
			 		case 7:{clearSegment();sevenDigit1();}break;
			 		case 8:{clearSegment();eightDigit1();}break;
			 		case 9:{clearSegment();nineDigit1();}	break;		
			 	}
				break;
		    }
		
	
		};
 
		powNumber=powNumber/10;

	
	 	
//	return reasult=(reasultNumber1||reasultNumber2||reasultNumber3) ;
	  	
    }
   
 }


	void clearSegment(void)
	{
		
		CONFIGH_SEG1 = INPUT;
		CONFIGH_SEG2 = INPUT;
		CONFIGH_SEG3 = INPUT;
		CONFIGH_SEG4 = INPUT;
		CONFIGH_SEG5 = INPUT;
		CONFIGH_SEG6 = INPUT;	
		
	}



