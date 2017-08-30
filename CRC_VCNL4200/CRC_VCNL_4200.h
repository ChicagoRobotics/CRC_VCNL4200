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

#define VCNL4200_I2CADDR_DEFAULT 0x13

// commands and constants
#define VCNL4200_COMMAND 0x80
#define VCNL4200_PRODUCTID 0x81
#define VCNL4200_PROXRATE 0x82
#define VCNL4200_IRLED 0x83
#define VCNL4200_AMBIENTPARAMETER 0x84
#define VCNL4200_AMBIENTDATA 0x85
#define VCNL4200_PROXIMITYDATA 0x87
#define VCNL4200_INTCONTROL 0x89
#define VCNL4200_PROXINITYADJUST 0x8A
#define VCNL4200_INTSTAT 0x8E
#define VCNL4200_MODTIMING 0x8F

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
	CRC_VCNL4200();
	boolean begin(uint8_t a = VCNL4200_I2CADDR_DEFAULT);
	uint8_t getLEDcurrent(void);
	void setLEDcurrent(uint8_t c);
	void setFrequency(VCNL4200_freq f);
	uint16_t readProximity(void);
	uint16_t readAmbient(void);

private:
	void write8(uint8_t address, uint8_t data);
	uint16_t read16(uint8_t address);
	uint8_t read8(uint8_t address);
	uint8_t _i2caddr;
};