//
// Created by Administrator on 2018-04-18.
//

#ifndef CAR_SCANER_H
#define CAR_SCANER_H

#include <Servo.h>
#include "CoordinateSystem.h"
using namespace coordinateSystem;

class Scaner {
	// control of ultrasonic sensor & servo motor

//private:
public:
	// pin of ultrasonic sensor (ex HC-SR04)
	int pinUltrasonicTrig;
	int pinUltrasonicEcho;

	// pin of servo motor (ex TowerPro SG90)
	int pinServo;

	// servo motor's pulse width range (ex 500-2400)
	int pulseMin;
	int pulseMax;

	Servo scanerServo;

public:
	// default pulse min & max is based on TowerPro SG90 Servo
	Scaner(int pinUltrasonicTrig, int pinUltrasonicEcho, int pinServo, int pulseMin = 500, int pulseMax = 2400);

public:
	double measureDistance();
	PolarPoint* scan(double degree); //return array of PolarPoint

	// density is the number of scan per 1 degree
	PolarPoint* scanArea(double startDegree, double endDegree, double density = 1.0);
	PolarPoint* scan180(double density = 1.0);
//	PolarPoint<double>* scan360(double density = 1.0);

protected:
	double setServoDegree(double degree); // return difference with param; unit as degree
};


#endif //CAR_SCANER_H
