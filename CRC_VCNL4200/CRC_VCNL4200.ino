/*
 Name:		CRC_VCNL4200.ino
 Created:	8/27/2017 4:10:37 PM
 Author:	jlaing
*/

#include <Wire.h>
#include "CRC_VCNL_4200.h"

CRC_VCNL4200 vcnl4200;

void setup() {
	Serial.begin(9600);
	while (!Serial);
	Serial.println("Booting.");
	if (vcnl4200.exists()) {
		Serial.println("VCNL4200 found");
		vcnl4200.initialize();
		Serial.println("VCNL4200 initialized");
	}
}

void loop() {
	Serial.print("Proximity: ");
	Serial.println(vcnl4200.getProximity());
	Serial.print("Ambient: ");
	Serial.println(vcnl4200.getAmbient());
	Serial.println();
	delay(2000);
}


