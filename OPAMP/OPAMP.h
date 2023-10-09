
#include "BA45F5240.h"


//OPAMP 
bit FT=0;	//opamp ofset callbration
int V_op0;
int V_op1;
char VA0OS,VA0OS1,VA0OS2;
char VA1OS,VA1OS1,VA1OS2;
bit opamp0,opamp1;
	//OPAMP EN
	#define OPAMP_0_ENABLE  _sda0en=1;
	#define OPAMP_0_DISABLE  _sda0en=0;

	#define OPAMP_1_ENABLE  _sda0en=1;
	#define OPAMP_1_DISABLE  _sda1en=0;
	







	