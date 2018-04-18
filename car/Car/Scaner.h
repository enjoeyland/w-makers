//
// Created by Administrator on 2018-04-18.
//

#ifndef CAR_SCANER_H
#define CAR_SCANER_H

#include "CoordinateSystem.h"
using namespace coordinateSystem;

class Scaner {
private:
	int pinUltrasonicTrig;
	int pinUltrasonicEcho;
	int pinServo;
	int pulseMin;
	int pulseMax;
	Servo scanerServo;

public:
	Scaner(int pinUltrasonicTrig, int pinUltrasonicEcho, int pinServo, int pulseMin = 500, int pulseMax = 2400);
	// default pulse min & max is based on TowerPro SG90 Servo
	~Scaner();

public:
	double measureDistance();
	PolarPoint<double>* scan(double degree); //return array of PolarPoint

	// density is the number of scan per 1 degree
	PolarPoint<double>* scanSpecific(double startDegree, double endDegree, double density = 1.0); 
	PolarPoint<double>* scan180(double density = 1.0);
	PolarPoint<double>* scan360(double density = 1.0);

protected:
	double setServoDegree(double degree); // return difference with param; unit as degree
};


#endif //CAR_SCANER_H
