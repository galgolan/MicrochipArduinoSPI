#include "Arduino.h"
#include "mcp49x2.h"
#include "SPI.h"

MCP49x2::MCP49x2(int selectPin)
{
	_selectPin = selectPin;
}

void MCP49x2::start()
{
	SPI.begin();
}

void MCP49x2::setup()
{
	pinMode(_selectPin, OUTPUT);
	digitalWrite(_selectPin, HIGH);
	
	SPI.setDataMode(SPI_MODE0);
	SPI.setClockDivider(SPI_CLOCK_DIV32);  // 16MHz/32=0.5MHz
	SPI.setBitOrder(MSBFIRST);
}

void MCP49x2::program(byte configuration, int data)
{
	digitalWrite(_selectPin, LOW);
	int instruction = (configuration << 4) | (data & 0x0FFF);
	SPI.transfer(instruction);
	digitalWrite(_selectPin, HIGH);
}