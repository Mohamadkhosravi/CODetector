#include "KEY.h"


 buttonType key(void){
		
      buttonType buttonStatus;

		
		if(KEY_PIN == SET )	
		{
			
			debounceCounter++;
			buttonStatus  =IDLE;
			pressFlag=1;
		
			if ((pressLockFlag==1)&&(pressFlag==1))
			{
				keyState=(!keyState);
			    keyCounter=0;
				pressLockFlag=0;
			}
			if(debounceCounter > DEBOUNCE_THRESHOLD)
			{
				pressFlag=2;	
			
			}
			
		}
		if((KEY_PIN == RESET)&&(pressFlag ==1))
		{
			pressLockFlag=1;
			debounceCounter=0;
			
			clearSegment();
			_papu4=1;
			_pawu4=1;
		
		   if((keyState==1))
			{
		
		  	  buttonStatus  =DOUBLE;
		  	  keyCounter++;
		  	  
		  	  if(keyCounter>= PRESS_STATE_TIMOUT)
		  	  {
		  	  	debounceCounter=0;
		  	  	pressFlag=0;
		  	  	keyCounter=0;
		  	  }
			 // pressCount=1;
				
			}
		    if((keyState==0))
		    {
				buttonStatus= SINGLE;
				keyCounter++;
				if(keyCounter>= PRESS_STATE_TIMOUT)
				{
					debounceCounter=0;
					pressFlag=0;
					keyCounter=0;
				}
				
		    }
		
		    clearSegment();	
		   
			_papu4=1;
			_pawu4=1;
		
		
		}  
		if((KEY_PIN == RESET)&&(pressFlag ==2))
		{    
			buttonStatus =LONGPRESS;
			keyCounter++;
			
		     if(keyCounter>= LONGPRESS_TIMOUT)
		  	  {
		  	  	debounceCounter=0;
		  	  	pressFlag=0;
		  	  	keyCounter=0;
		  	  }
			
			
		}
		
		if((pressFlag ==0))
		{
			buttonStatus= NONPRESS;			
		}
		return buttonStatus;
		
	 }  	   	 
	