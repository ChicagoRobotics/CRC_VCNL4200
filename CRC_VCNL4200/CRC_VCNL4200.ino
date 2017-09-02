/*
 Name:		CRC_VCNL4200.ino
 Created:	8/27/2017 4:10:37 PM
 Author:	jlaing
*/

#include <Wire.h>
#include "CRC_VCNL_4200.h"
#define SENSOR_ADDR 0x51

CRC_VCNL4200 vcnl4200;

void setup() {
	Serial.begin(9600);
	while (!Serial);
	Serial.println("Booting test.");

	if (!vcnl4200.begin()) {
		Serial.println("VCNL4200 not found");
		while (1);
	}
	Serial.println("Found VCNL4200");


	//Wire.begin();

	//Write to ALS_CONF to turn Ambient Light Sensor (ALS) off.
	//write_register(SENSOR_ADDR, 0x0, B01000001, B00000000); //Original settings
	//write_register(SENSOR_ADDR, 0x0, B01000000, B00000000); //Jamie settings

	////Write to PS_CONF1 and PS_CONF2 to set Proximity Sensor (PS) settings.
	//write_register(SENSOR_ADDR, 0x3, B00011010, B00001000);

	////Write to PS_CONF3 and PS_MS to set Proximity Sensor (PS) settings.
	//write_register(SENSOR_ADDR, 0x4, B01110000, B00000111);

	////Write to PS_THDL_L and PS_THDL_H to set Proxmitt Sensor (PS) Threshhold.
	//write_register(SENSOR_ADDR, 0x6, B00010000, B00000000);
	
}

void loop() {

	//int reg = 0x8; //Proximity Sensor (PS) output
	//Wire.beginTransmission(SENSOR_ADDR);
	//Wire.write(reg);
	//Wire.endTransmission(false);
	////Read data
	//byte prox[2] = { 0, 0 };  //The sensor provides the output over 2 bytes.
	//Wire.requestFrom(SENSOR_ADDR, 2);
	//prox[0] = Wire.read();
	//prox[1] = Wire.read();
	//int value = int(prox[1]) * 256 + int(prox[0]); //Combines bytes
	//Serial.print("Proximity: ");
	//Serial.println(value);

	//int reg2 = 0x9; //Ambient Light Sensor (ALS) output
	//Wire.beginTransmission(SENSOR_ADDR);
	//Wire.write(reg2);
	//Wire.endTransmission(false);
	////Read data
	//byte amb[2] = { 0, 0 };  //The sensor provides the output over 2 bytes.
	//Wire.requestFrom(SENSOR_ADDR, 2);
	//amb[0] = Wire.read();
	//amb[1] = Wire.read();
	//int value2 = int(amb[1]) * 256 + int(amb[0]); //Combines bytes
	//Serial.print("Ambient: ");
	//Serial.println(value2);

	Serial.println("Loop complete");
	Serial.println();
	delay(2000);
}

//void write_register(int device_addr, int register_num, int low_byte, int high_byte)
//{
//	Wire.beginTransmission(device_addr);
//	Wire.write(register_num);
//	Wire.write(low_byte);
//	Wire.write(high_byte);
//	Wire.endTransmission();
//}

//unsigned int readProximity() {
//	// readProximity() returns a 16-bit value from the VCNL4000's proximity data registers
//	byte temp = readVCNLByte(0x80);
//	writeVCNLByte(0x80, temp | 0x08); // command the sensor to perform a proximity measure
//
//	while (!(readVCNLByte(0x80) & 0x20)); // Wait for the proximity data ready bit to be set
//	unsigned int data = readVCNLByte(0x87) << 8; data |= readVCNLByte(0x88); return data;
//} 
//unsigned int readAmbient() { 
//	// readAmbient() returns a 16-bit value from the VCNL4000's ambient light data registers 
//	byte temp = readVCNLByte(0x80); 
//	writeVCNLByte(0x80, temp | 0x10); // command the sensor to perform ambient measure 
//	while(!(readVCNLByte(0x80)&0x40)); // wait for the proximity data ready bit to be set 
//	unsigned int data = readVCNLByte(0x85) << 8; data |= readVCNLByte(0x86); 
//	return data; 
//} 
//void writeVCNLByte(byte address, byte data){ 
//	// writeVCNLByte(address, data) writes a single byte of data to address 
//	Wire.beginTransmission(VCNL4000_ADDRESS); 
//	Wire.write(address); 
//	Wire.write(data); 
//	Wire.endTransmission(); 
//} 
//byte readVCNLByte(byte address){ 
//	// readByte(address) reads a single byte of data from address 
//	Wire.beginTransmission(VCNL4000_ADDRESS); 
//	Wire.write(address); 
//	Wire.endTransmission(); 
//	Wire.requestFrom(VCNL4000_ADDRESS, 1); 
//	while(!Wire.available()); 
//	byte data = Wire.read(); 
//	return data; 
//}


