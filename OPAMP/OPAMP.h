
#include "BA45F5240.h"


//OPAMP 
bit FT=0;	//opamp ofset callbration
int V_op0;
int V_op1;
char VA0OS,VA0OS1,VA0OS2;
char VA1OS,VA1OS1,VA1OS2;
bit opamp0,opamp1;
	//OPAMP EN
	#define OP0EN _sda0en
	#define OP1EN _sda1en
	
void OPAMPInit(char R1,char R2,char R3);



	