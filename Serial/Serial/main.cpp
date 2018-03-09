/*
 * Serial.cpp
 *
 * Created: 01.03.2018 16:12:54
 * Author : Erik
 */ 


#include <asf.h>
#include "lib/Serial/Serial.h"


int main(void)
{
	system_init();
	delay_init();
	 
	char* myString;
	Serial mySerial;
	mySerial.initialize(SerialBaudrate::baud115200, SerialPort::SerialPort1);
	
	
	while (true) {
		myString = mySerial.readString();
		delay_ms(50);
		/*
		mySerial.writeString("Echo: ", 6);
		mySerial.writeString(myString, 20);
		mySerial.writeString("\n", 1);
		*/
		
	}
}
