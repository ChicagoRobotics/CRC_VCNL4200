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
	Wire.write(VCNL4200_DeviceID_REG);
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
	set_ALS_CONF();
	set_PS_CONF1_CONF2();
	set_PS_CONF3_MS();

	//Set the PS interrupt levels
	write16_LowHigh(VCNL4200_PS_THDL_REG, B10001000, B00010011);
	write16_LowHigh(VCNL4200_PS_THDH_REG, B11100000, B00101110);

	return true;
}

boolean CRC_VCNL4200::set_ALS_CONF(uint8_t settingTotal) {
	write16_LowHigh(VCNL4200_ALS_CONF_REG, settingTotal, B00000000);
	return true;
}

boolean CRC_VCNL4200::set_PS_CONF1_CONF2(uint8_t conf1, uint8_t conf2) {
	write16_LowHigh(VCNL4200_PS_CONF1_CONF2_REG, conf1, conf2);
	return true;
}

boolean CRC_VCNL4200::set_PS_CONF3_MS(uint8_t conf3, uint8_t ms) {
	Serial.print("Conf3, MS:");
	Serial.print(conf3);
	Serial.print(", ");
	Serial.println(ms);
	write16_LowHigh(VCNL4200_PS_CONF3_MS_REG, conf3, ms);
	return true;
}

uint16_t CRC_VCNL4200::getProximity() {
	return readData(VCNL4200_PROXIMITY_REG);
}

uint16_t CRC_VCNL4200::getProxLowInterrupt() {
	return readData(VCNL4200_PS_THDL_REG);
}

uint16_t CRC_VCNL4200::getProxHighInterrupt() {
	return readData(VCNL4200_PS_THDH_REG);
}

uint8_t CRC_VCNL4200::getInterruptFlag() {
	uint8_t reading;
	reading = readData(VCNL4200_INT_FLAG_REG);
	return reading;
}

uint16_t CRC_VCNL4200::getAmbient() {
	return readData(VCNL4200_AMBIENT_REG);
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
