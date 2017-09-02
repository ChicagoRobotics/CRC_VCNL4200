// CRC_VCNL_4200.h

#ifndef _CRC_VCNL_4200_h
	#define _CRC_VCNL_4200_h
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
	#include <Wire.h>
#endif

#define VCNL4200_I2CADDR 0x51
#define VCNL4200_DeviceID 0x0E

typedef enum
{
	VCNL4200_3M125 = 3,
	VCNL4200_1M5625 = 2,
	VCNL4200_781K25 = 1,
	VCNL4200_390K625 = 0,
} VCNL4200_freq;

#define VCNL4200_MEASUREAMBIENT 0x10
#define VCNL4200_MEASUREPROXIMITY 0x08
#define VCNL4200_AMBIENTREADY 0x40
#define VCNL4200_PROXIMITYREADY 0x20

class CRC_VCNL4200 {
public:
	CRC_VCNL4200(); // existing
	boolean begin();
	uint8_t getLEDcurrent(void); // existing
	void setLEDcurrent(uint8_t c); // existing
	void setFrequency(VCNL4200_freq f); // existing
	uint16_t readProximity(void); // existing
	uint16_t readAmbient(void); // existing

private:
	void write8(uint8_t address, uint8_t data); // existing
	uint8_t write16_LowHigh(uint8_t address, uint8_t low, uint8_t high);
	uint16_t readData(uint8_t command_code);
	uint8_t _i2caddr; // existing
};