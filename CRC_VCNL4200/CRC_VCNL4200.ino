/*
 Name:		CRC_VCNL4200.ino
 Created:	8/27/2017 4:10:37 PM
 Author:	jlaing
*/

#include "CRC_VCNL_4200.h"

CRC_VCNL4200 v4200;
int ledPin = 13;
int sdaPin = 20;

void setup() {
	Serial.begin(9600);
	Serial.println("Booting VCNL 4200 test");
	pinMode(ledPin, OUTPUT);
	pinMode(sdaPin, OUTPUT);

	if (!v4200.begin()) {
		Serial.println("Sensor not found :(");
		while (1);
	}
	Serial.println("Found VCNL 4200");
}

void loop() {
	Serial.print("Ambient: "); 
	Serial.println(v4200.readAmbient());
	Serial.print("Proximity: "); 
	Serial.println(v4200.readProximity());
	digitalWrite(ledPin, HIGH);
	digitalWrite(sdaPin, HIGH);
	delay(2000);                  // waits for a second
	digitalWrite(ledPin, LOW);    // sets the LED off
	digitalWrite(sdaPin, LOW);
	delay(2000);
}

