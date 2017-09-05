// CRC_VCNL4200.h

#ifndef _CRC_VCNL4200_h
#define _CRC_VCNL4200_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
	#include <Wire.h>
#endif

//Register declarations
#define VCNL4200_I2CADDR 0x51
#define VCNL4200_ALS_CONF_REG 0x00
#define VCNL4200_ALS_THDH_REG 0x01 //Ambient Light Sensor Threshold Data High
#define VCNL4200_ALS_THDL_REG 0x02 //Ambient Light Sensor Threshold Data Low
#define VCNL4200_PS_CONF1_CONF2_REG 0x03
#define VCNL4200_PS_CONF3_MS_REG 0x04 //Conf3 and Mode Select
#define VCNL4200_PS_CANC_REG 0x05
#define VCNL4200_PS_THDL_REG 0x06 //Proximity Sensor Threshold Data Low
#define VCNL4200_PS_THDH_REG 0x07 //Proximity Sensor Threshold Data High
#define VCNL4200_PROXIMITY_REG 0x08
#define VCNL4200_AMBIENT_REG 0x09
#define VCNL4200_WHITE_REG 0x0A
#define VCNL4200_INT_FLAG_REG 0x0D
#define VCNL4200_DeviceID_REG 0x0E


//Ambient Light Sensor Shut Down
typedef enum {
	VCNL4200_ALS_Shutdown_on = 0,
	VCNL4200_ALS_Shutdown_off = 1
} VCNL4200_ALS_Shutdown;

//Ambient Light Sensor Interrupt
typedef enum {
	VCNL4200_ALS_Interrupt_disable = 0,
	VCNL4200_ALS_Interrupt_enable = 2
} VCNL4200_ALS_Interrupt;

//Ambient Light Persistence Setting
typedef enum {
	VCNL4200_ALS_Pers_one = 0,
	VCNL4200_ALS_Pers_two = 4,
	VCNL4200_ALS_Pers_four = 8,
	VCNL4200_ALS_Pers_eight = 12
} VCNL4200_ALS_Pers;

//Ambient Light Sensor Interrupt
typedef enum {
	VCNL4200_ALS_INT_SWITCH_als = 0,
	VCNL4200_ALS_INT_SWITCH_white = 32
} VCNL4200_ALS_INT_SWITCH;

//Ambient Light Sensor Integration Time in Milliseconds
typedef enum {
	VCNL4200_ALS_IT_ms50 = 0,
	VCNL4200_ALS_IT_ms100 = 64,
	VCNL4200_ALS_IT_ms200 = 128,
	VCNL4200_ALS_IT_ms400 = 192
} VCNL4200_ALS_IT;


class CRC_VCNL4200 {
public:
	CRC_VCNL4200();
	boolean exists();
	boolean initialize();
	
	//Edit the binary settings here to change default startup options
	boolean set_ALS_CONF(uint8_t c1 = B01000000);
	boolean set_PS_CONF1_CONF2(uint8_t c1 = B00101010, uint8_t c2 = B00001011);
	boolean set_PS_CONF3_MS(uint8_t c3 = B01110000, uint8_t m = B00000111);
	
	uint16_t getProximity();
	uint16_t getAmbient();
	uint16_t getProxLowInterrupt();
	uint16_t getProxHighInterrupt();
	uint8_t getInterruptFlag();

private:
	uint8_t _i2caddr;
	void write8(uint8_t address, uint8_t data);
	uint8_t write16_LowHigh(uint8_t address, uint8_t low, uint8_t high);
	uint16_t readData(uint8_t command_code);
};