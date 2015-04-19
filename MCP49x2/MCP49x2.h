/*
	MCP49x2.h - library for controlling Microchip's MCP49x2 series DACs using
	Arduino's hardware SPI interface.
	Created by Gal Golan
	Released into the public domain.
*/

#ifndef _MCP49x2_H_
#define _MCP49x2_H_

#include "Arduino.h"

#define DAC_A  			B0000
#define DAC_B  			B1000

#define DAC_BUFFERED  	B0100
#define DAC_UNBUFFERED  B0000
#define DAC_GAIN_1  	B0010
#define DAC_GAIN_2  	B0000
#define DAC_ACTIVE  	B0001
#define DAC_SHUTDOWN  	B0000

class MCP49x2
{
	public:
		MCP49x2(int selectPin);
		void start();
		void program(byte configuration, int data);
		
	private:
		int _selectPin;
		
		void setup();
};

#endif