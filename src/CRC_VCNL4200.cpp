#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>
#include "CRC_VCNL4200.h"

CRC_VCNL4200::CRC_VCNL4200() { 
	_i2caddr = VCNL4200_I2CADDR;
}

boolean CRC_VCNL4200::exists() {
	Wire.begin();
	uint8_t rev = 0;
	Wire.beginTransmission(_i2caddr);
	Wire.write(VCNL4200_DeviceID);
	Wire.endTransmission(false);
	Wire.requestFrom(_i2caddr, uint8_t(2));
	byte lowByte = Wire.read();
	byte highByte = Wire.read();
	//Strange that highByte returns 0x10 while documentation says it should return 0x01
	if ((lowByte == 0x58) && (highByte == 0x10)) {
		return true;
	}
	return false;
}

boolean CRC_VCNL4200::initialize() {
	write16_LowHigh(0x0, B01000000, B00000000);
	write16_LowHigh(0x3, B00011010, B00001000);
	write16_LowHigh(0x4, B01110000, B00000111);
	write16_LowHigh(0x6, B00010000, B00000000);
	return true;
}

uint16_t CRC_VCNL4200::getProximity() {
	return readData(VCNL4200_PROXIMITY);
}

uint16_t CRC_VCNL4200::getAmbient() {
	return readData(VCNL4200_AMBIENT);
}

uint16_t CRC_VCNL4200::readData(uint8_t command_code)
{
	uint16_t reading;
	Wire.beginTransmission(_i2caddr);
	Wire.write(command_code);
	Wire.endTransmission(false);
	Wire.requestFrom(_i2caddr, uint8_t(2));
	while (!Wire.available());
	uint8_t byteLow = Wire.read();
	while (!Wire.available());
	uint16_t byteHigh = Wire.read();
	reading = (byteHigh <<= 8) + byteLow;
	return reading;
}

void CRC_VCNL4200::write8(uint8_t address, uint8_t data) //Original
{
	Wire.beginTransmission(_i2caddr);
	Wire.write(address);
	Wire.write(data);
	Wire.endTransmission();
}

uint8_t CRC_VCNL4200::write16_LowHigh(uint8_t address, uint8_t low, uint8_t high)
{
	Wire.beginTransmission(_i2caddr);
	Wire.write(address);
	Wire.write(low);
	Wire.write(high);
	Wire.endTransmission();
}
