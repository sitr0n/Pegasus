/*
 * Serial.h
 *
 * Created: 02.03.2018 21:14:48
 *  Author: Erik
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

#include <asf.h>
#include "conf\confUSART.h"
#include "SerialParameters.h"


class Serial
{
	public:
	void	initialize(SerialBaudrate::Baudrate baud, SerialPort::Port port);
	
	char	read();
	char*	readString();
	void	write(char txByte);
	void	writeString(char* txString, uint16_t size);
	
	private:
	char rxBuffer[64];
	
	struct usart_module usartModule;
	struct usart_config usartConfig;
};



#endif /* SERIAL_H_ */