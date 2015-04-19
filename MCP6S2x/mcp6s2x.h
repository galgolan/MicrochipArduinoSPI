/*
	MCP6s2x.h - Library for controlling Microchip's PGA (MCP6S2x) ICs using Arduino's
	hardware SPI library.
	Created by Gal Golan
	Released into the public domain.
*/
#ifndef _MCP6S2X_H_
#define _MCP6S2X_H_

#include "Arduino.h"

#define GAIN_1   B00000000
#define GAIN_2   B00000001
#define GAIN_4   B00000010
#define GAIN_5   B00000011
#define GAIN_8   B00000100
#define GAIN_10  B00000101
#define GAIN_16  B00000110
#define GAIN_32  B00000111

class MCP6s2x
{
	public:
		// setup the SPI library to use MCP6s2x
		MCP6s2x(int slaveSelectPin);
		// sets the input channel
		void setChannel(byte channel);
		// sets the gain of the current channel
		void setGain(byte gain);
		// starts the SPI interface
		void start(void);
		
	private:
		int _slaveSelect;
		void setup(void);
		void program(byte instruction, byte data);
};

#endif