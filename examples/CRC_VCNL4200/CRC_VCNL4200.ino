/*
 Name:		CRC_VCNL4200.ino
 Created:	8/27/2017 4:10:37 PM
 Author:	jlaing
*/

#include "CRC_VCNL4200.h"
CRC_VCNL4200 vcnl4200;
int pinReading = 0;

void setup() {
	Serial.begin(9600);
	while (!Serial);
	Serial.println("Booting.");
	if (vcnl4200.exists()) {
		Serial.println("VCNL4200 found");
		vcnl4200.initialize();
		Serial.println("VCNL4200 initialized");
	}
	pinMode(7, INPUT);
	pinMode(13, OUTPUT);
}

void loop() {
	
	Serial.print("Proximity: ");
	Serial.println(vcnl4200.getProximity());
	Serial.print("Ambient: ");
	Serial.println(vcnl4200.getAmbient());

	//Check interrupt pin
	pinReading = digitalRead(7);
	//Set LED to interrupt pin HIGH/LOW
	Serial.print("High interrupt: ");
	Serial.println(vcnl4200.getProxHighInterrupt());
	Serial.print("Low interrupt: ");
	Serial.println(vcnl4200.getProxLowInterrupt());

	if (pinReading == HIGH) {
		Serial.println("Interrupt false");
		digitalWrite(13, LOW);
	}
	else {
		Serial.println("Interrupt true, flag:");
		Serial.print(vcnl4200.getInterruptFlag());
		digitalWrite(13, HIGH);
	}

	Serial.println();
	delay(2000);
}
