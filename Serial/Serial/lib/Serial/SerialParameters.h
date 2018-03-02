/*
 * SerialParameters.h
 *
 * Created: 02.03.2018 21:18:38
 *  Author: Erik
 */ 


#ifndef SERIALPARAMETERS_H_
#define SERIALPARAMETERS_H_

namespace SerialPort
{
	enum Port {
		SerialPort1,
		SerialPort2
	};
};

namespace SerialBaudrate
{
	enum Baudrate {
		baud4800	= 4800,
		baud9600	= 9600,
		baud19200	= 19200,
		baud38400	= 38400,
		baud57600	= 57600,
		baud115200	= 115200,
		baud230400	= 230400,
		baud250000	= 250000
	};
};



#endif /* SERIALPARAMETERS_H_ */