//
// Created by Administrator on 2018-04-18.
//

#include "Scaner.h"
#include <Arduino.h>
#include <Servo.h>
//#include <vector>

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

	double distance = duration * 0.0172; // 334m/s / 2(왕복 제거)
	return distance;
}

PolarPoint<double>* Scaner::scan(double degree) {
	double degreeDiff = setServoDegree(degree);
	double distance = measureDistance();
	PolarPoint<double> scanData[1];
	scanData[0].SetInfo(degree - degreeDiff, distance);
	return scanData;
}

PolarPoint<double>* Scaner::scanArea(double startDegree, double endDegree, double density) {
	// startDegree <= endDegree
	// as of now endDegree can be maximum 180
	if (startDegree == endDegree) {
		return scan(startDegree);
	}

	int scanDataSize = (int) (abs(startDegree - endDegree) * density) + 1;
	PolarPoint<double> scanData[scanDataSize];
	for (int i = 0; i < scanDataSize; i++) {
		PolarPoint<double>* scanDataSegment = scan(startDegree + i / density);
		scanData[i].SetInfo(scanDataSegment->degree, scanDataSegment->radialDistance);
	}
	return scanData;
}

PolarPoint<double>* Scaner::scan180(double density) {
	return scanArea(0.0, 180.0, density);
}

//PolarPoint<double>* Scaner::scan360(double density) {
//	vector<PolarPoint> scanDataVector;
//	scanDataVector.reserve((int) (360 * density));
//  // spinning should have CarMovement instance
//}

double Scaner::setServoDegree(double degree) {
	long realPulseWidth = map(degree, 0, 180, pulseMin, pulseMax);
	int practicalPulseWidth = (int) realPulseWidth;
	scanerServo.writeMicroseconds(practicalPulseWidth);
	double diff = (double) (map( (long) (realPulseWidth) - practicalPulseWidth, pulseMin, pulseMax, 0, 180));
	return diff; // return difference with param; unit as degree
}