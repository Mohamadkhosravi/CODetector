#include "CO.h"

int ReadCO(float VCC,unsigned int ADCAmplifier,unsigned short int temperatur){

	
	// float temperatur=0.0;
	 float VAmplifier1=0.0;
	 unsigned int CO ;
	
  
  
	VAmplifier1=ADCAmplifier*((VCC)/4095);
	CO = ((((VAmplifier1)/gainAmplifier1*1000)/RSHANT)*1000)*slope;
   
        if (temperatur<0)
		{
		 	return (((-0.75*(temperatur+20)+60))/100)*CO;	
		} 
        else if ((temperatur>=0)&&(temperatur<20))
		{
	    	return  ((0.25*(temperatur)+75)/100)*CO;
		}
	    else if ((temperatur>=20)&&(temperatur<50))
		{	
			return ((1.1666*(temperatur-20)+100)/100)*CO;
		}
	   else if ((temperatur>=50))
		{	
		   return (((0.5*(temperatur-50)+135)/100))*CO;

		}

	



}






