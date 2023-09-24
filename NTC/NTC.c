
#include "NTC.h"
/*
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Sink Current Generator
	
	//Sink current generator enable control
	_isgen=1;
	
	//Sink current generator control for ISINK0 pin
	//Current value (mA) = 50 + 10 × (ISGDATA0[4:0])
	_isgdata0=0b00000000;
	
	//Sink current generator control for ISINK1 pin
	//Current value (mA) = 50 + 5 × (ISGDATA1[4:0])
	_isgdata1=0b00000000;
	
	
	
	//Enable/Disable ISINK0 pin sink current control
	_isgs0=0;
	
	//Enable/Disable ISINK1 pin sink current control
	_isgs1=0;

/////////////////////////////////////////////////////////////////////////////////////////////////////
*/

#ifdef _USE_MATH_H
// Nothing additional is needed here when using math.h
#else
	
	int n=0;
	
	double custom_log(double x) {
		
		if (x <= 0) {
			
			return -1.0; // Not defined for non-positive numbers
		}
		
		float epsilon = 1e-10; // Small value for accuracy
		float result = 0.0;
		float term = (x - 1) / (x + 1);
		float term_squared = term * term;
		float term_squared_power = term_squared;
		float current_term = term;
		
		for ( n = 1; current_term > epsilon; n++) {
			
			result += current_term;
			current_term = term_squared_power * term;
			term_squared_power *= term_squared;
			current_term /= 2 * n + 1;
		}

   	 return 2 * result;
    }
		
#endif

















float temperature(int ADCValue, float VDD) {


	float VNTC = CALCULATE_VNTC(ADCValue, ADCNumerOfbits ,VDD);
	float RNTC=CALCULATE_RNTC(VNTC , VDD  ,RES_PULLDOWN_NTC);
	
	float logResistance = LOG_FUNCTION(RNTC*VDD);	


	// 1/A+B*LN(RNTC)*C((LN(RNTC)^3)
	
	float temperatureKelvin = 1.0 / (A + B *logResistance + C *logResistance*logResistance*logResistance);
	float temperatureCelsius = temperatureKelvin - 273.15;
	
	return temperatureCelsius;

}