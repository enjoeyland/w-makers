#include "CarMovementSerialPrint.h"
#include <Arduino.h>


// CarMovementSerialPrint
void CarMovementSerialPrint::goForward(double speed, double distance) {
	Serial.println('F');
}

void CarMovementSerialPrint::goBackward(double speed, double distance) {
	Serial.println('B');
}

void CarMovementSerialPrint::stop() {
	Serial.println('S');
}

void CarMovementSerialPrint::turnLeft(double average_speed, double radius, double degree) {
	if (average_speed > 0.0) {
		Serial.println('G');
	} else {
		Serial.println('H');
	}
}

void CarMovementSerialPrint::turnRight(double average_speed, double radius, double degree) {
	if (average_speed > 0.0) {
		Serial.println('I');
	} else {
		Serial.println('J');
	}
}

void CarMovementSerialPrint::spinLeft(double average_speed, double radius, double degree) {
	Serial.println('L');
}

void CarMovementSerialPrint::spinRight(double average_speed, double radius, double degree) {
	Serial.println('R');
}

