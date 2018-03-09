#ifndef _AMC_H_
#define _AMC_H_

#include <Arduino.h>

class AMC {
	protected:
	
	public:
		AMC(double Kp, double Ti, uint16_t h);
		uint32_t tick(int r, int y);

	private:
		double _Kp;
		double _Ti;
		uint16_t _h;
		int _ek;
		uint32_t _uk;
}

#endif
