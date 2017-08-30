/*
 Name:		CRC_VCNL4200.ino
 Created:	8/27/2017 4:10:37 PM
 Author:	jlaing
*/

#include "CRC_VCNL_4200.h"
int ledPin = 13;
int sdaPin = 20;

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(sdaPin, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	digitalWrite(ledPin, HIGH);   // sets the LED on
	digitalWrite(sdaPin, HIGH);
	delay(2000);                  // waits for a second
	digitalWrite(ledPin, LOW);    // sets the LED off
	digitalWrite(sdaPin, LOW);
	delay(2000);
}
