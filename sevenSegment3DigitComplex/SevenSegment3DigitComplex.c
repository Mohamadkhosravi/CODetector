
#include<sevenSegment3DigitComplex.h>




void errorSeg(void){
	//clearSegment();
/*	CONFIGH_SEG1=OUTPUT;
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
    //=================== o*/
 
}




void error1Seg(void){
   /* clearSegment();
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
    GCC_DELAY(1000);*/
}


void ziroDigit1(void){
	

		
	
	

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

	 
 	
}
 
void oneDigit1(void){

	clearSegment();
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG3=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	SEG1=0;
	SEG3=1;
	SEG4=1;

}
void oneDigit2(void) {

	clearSegment();		
	CONFIGH_SEG1=OUTPUT;
	CONFIGH_SEG3=OUTPUT; 
	CONFIGH_SEG4=OUTPUT;
	SEG1=1;
	SEG3=0;
	SEG4=0;
//	GCC_DELAY(1000);
  
 }  
void oneDigit3(void){
	
		
	clearSegment();	
	CONFIGH_SEG2=OUTPUT;
	CONFIGH_SEG4=OUTPUT;
	 CONFIGH_SEG5=OUTPUT;
	 SEG2=1;
	 SEG4=0;
	 SEG5=0;
	 
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
	
	//GCC_DELAY(1000);	
	
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


}

void nineDigit1(void){
	
	

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
	 clearSegment();
	 ziroDigit1();
	 GCC_DELAY(1000);
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
				
			 	clearSegment();
		    	GCC_DELAY(1000);
	    	
			 	switch(digNumber)
			 	{
			 	
			 		case 0:{ziroDigit3(); }break;
			 		case 1:{oneDigit3();  }break;
			 		case 2:{towDigit3();  }break;
			 		case 3:{threeDigit3();}break;
			 		case 4:{fourDigit3(); }break;
			 		case 5:{fiveDigit3(); }break;
			 		case 6:{sixDigit3();  }break;
			 		case 7:{sevenDigit3();}break;
			 		case 8:{eightDigit3();}break;
			 		case 9:{nineDigit3(); }break;
			 	
			 	
				}
				break;
			}

			case 2:
			{
				
			   	clearSegment();
		    	GCC_DELAY(1000);
		 
			 	switch(digNumber)
			 	{ 
			 		case 0:{ziroDigit2(); }break;
			 		case 1:{oneDigit2();  }break;
			 		case 2:{towDigit2();  }break;
			 		case 3:{threeDigit2();}break;
			 		case 4:{fourDigit2(); }break;
			 		case 5:{fiveDigit2(); }break;
			 		case 6:{sixDigit2();  }break;
			 		case 7:{sevenDigit2();}break;
			 		case 8:{eightDigit2();}break;
			 		case 9:{nineDigit2(); }break;
			 	}
				break;
			};
			
			case 3:
			{
				clearSegment();
	    	    GCC_DELAY(1000);
				
		 	    switch(digNumber)
			 	{
			 		case 0:{ziroDigit1(); }break;
			 		case 1:{oneDigit1();  }break;
			 		case 2:{towDigit1();  }break;
			 		case 3:{threeDigit1();}break;
			 		case 4:{fourDigit1(); }break;
			 		case 5:{fiveDigit1(); }break;
			 		case 6:{sixDigit1();  }break;
			 		case 7:{sevenDigit1();}break;
			 		case 8:{eightDigit1();}break;
			 		case 9:{nineDigit1(); }break;		
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



