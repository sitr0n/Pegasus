/*
 * Serial.cpp
 *
 * Created: 02.03.2018 21:15:42
 *  Author: Erik
 */ 


#include "Serial.h"

void Serial::initialize(SerialBaudrate::Baudrate baud, SerialPort::Port port)
{
	usart_get_config_defaults(&usartConfig);
	
	usartConfig.baudrate    = baud;
	usartConfig.mux_setting = configUSART_MUX_SETTING;
	usartConfig.pinmux_pad0 = configUSART_PINMUX_PAD0;
	usartConfig.pinmux_pad1 = configUSART_PINMUX_PAD1;
	usartConfig.pinmux_pad2 = configUSART_PINMUX_PAD2;
	usartConfig.pinmux_pad3 = configUSART_PINMUX_PAD3;
	
	while (usart_init(&usartModule, SERCOM0, &usartConfig) != STATUS_OK) {}
	usart_enable(&usartModule);
	
}

void Serial::write(char txByte)
{
	uint16_t tx = static_cast<uint16_t>(txByte);
	while(usart_write_wait(&usartModule, tx) != STATUS_OK) {}
}

void Serial::writeString(char* txString, uint16_t size)
{
	uint8_t* tx = reinterpret_cast<uint8_t*>(txString);
	while (usart_write_buffer_wait(&usartModule, tx, size) != STATUS_OK) {}
	/*
	for(uint8_t i = 0; txString[i] != '\0'; i++)
	{
		write(txString[i]);
	}
	*/
}

char Serial::read()
{
	uint16_t rx;
	while(usart_read_wait(&usartModule, &rx) != STATUS_OK) {}
	return static_cast<char>(rx);
}


char* Serial::readString()
{
	// TRY USING USART_READ_BUFFER_WAIT
	
	for (uint8_t j = 0; j < sizeof(rxBuffer); j++)
	{
		rxBuffer[j] = '\0';
	}
	
	for(uint8_t i = 0; i < 9; i++)
	{
		rxBuffer[i] = read();
	}
	
	return rxBuffer;
	
}
