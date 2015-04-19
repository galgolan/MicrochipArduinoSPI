#include "Arduino.h"
#include "mcp6s2x.h"
#include "SPI.h"

#define INST_SET_GAIN    B01000000
#define INST_SET_CHA     B01000001

MCP6s2x::MCP6s2x(int slaveSelectPin)
{
	_slaveSelect = slaveSelectPin;
	setup();
}

// initialize SPI library
void MCP6s2x::setup(void)
{
	pinMode(_slaveSelect, OUTPUT);
	digitalWrite(_slaveSelect, HIGH);
	
	SPI.setDataMode(SPI_MODE0);
	SPI.setClockDivider(SPI_CLOCK_DIV32);  // 16MHz/32=0.5MHz
	SPI.setBitOrder(MSBFIRST);
}

void MCP6s2x::start(void)
{
	SPI.begin();
}

void MCP6s2x::setChannel(byte channel)
{
	program(INST_SET_CHA, channel);
}

void MCP6s2x::setGain(byte gain)
{
	program(INST_SET_GAIN, gain);
}

void MCP6s2x::program(byte instruction, byte data)
{
  digitalWrite(_slaveSelect, LOW);
  SPI.transfer(instruction);
  SPI.transfer(data);
  digitalWrite(_slaveSelect, HIGH);
}