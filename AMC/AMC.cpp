/****************************************
	Core regulation class for drone flight
	
****************************************/

#include "AMC.h"
#DEFINE UPPER_LIMIT 200
#DEFINE LOWER_LIMIT 1

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
	
	if(_uk > UPPER_LIMIT) _uk = UPPER_LIMIT;
	if(_uk < LOWER_LIMIT ) _uk = LOWER_LIMIT;

	return _uk;  
}
