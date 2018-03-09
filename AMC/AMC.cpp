/****************************************
	Core regulation class for drone flight
	
****************************************/

#include "AMC.h"


AMC::AMC(double Kp, double Ti, uint16_t h)
{
	_Kp = Kp;
	_Ti = Ti;
	_h = h;
	_uk = 0;
	_uk = 0;
}

uint32_t AMC::tick(int r, int y)
{ 
	_uk += (uint32_t)( _Kp*((1+1/_Ti)*(r - y) - _ek));
	//Inverse error
	_ek = r - y;
	if(_uk > 200) _uk=200;
	if(_uk < 1 ) _uk=1;

	return uk;  
}
