//
// Created by Administrator on 2018-04-18.
//

#include "Scaner.h"
#include <Arduino.h>
#include <Servo.h>

Scaner::Scaner(int pinUltrasonicTrig, int pinUltrasonicEcho, int pinServo, int pulseMin, int pulseMax):
		pinUltrasonicTrig(pinUltrasonicTrig),
		pinUltrasonicEcho(pinUltrasonicEcho),
		pinServo(pinServo),
		pulseMin(pulseMin),
		pulseMax(pulseMax){
	scanerServo.attach(this->pinServo, pulseMin, pulseMax);
}

double Scaner::measureDistance() { // measure distance with servo motor
	digitalWrite(pinUltrasonicTrig, LOW); // init servo motor
	delayMicroseconds(2);

	digitalWrite(pinUltrasonicTrig, HIGH); // send pulse
	delayMicroseconds(10);
	digitalWrite(pinUltrasonicTrig, LOW);

	double duration = pulseIn(pinUltrasonicEcho, HIGH); // wait pulse

	double distance = duration * 0.0177; // 334m/s / 2(왕복 제거)
	return distance;
}

PolarPoint<double>* Scaner::scan(double degree) {

}

PolarPoint<double>* Scaner::scanSpecific(double startDegree, double endDegree, double density) {

}

PolarPoint<double>* Scaner::scan180(double density) {

}

PolarPoint<double>* Scaner::scan360(double density) {

}

double Scaner::setServoDegree(double degree) {
	long realPulseWidth = map(degree, 0, 180, pulseMin, pulseMax);
	int practicalPulseWidth = static_cast<int>(realPulseWidth);
	scanerServo.writeMicroseconds(practicalPulseWidth);
	double diff = static_cast<double> (map(static_cast<long>(realPulseWidth) - practicalPulseWidth, pulseMin, pulseMax, 0, 180));
	return diff; // return difference with param; unit as degree
}