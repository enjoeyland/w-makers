//
// Created by Administrator on 2018-05-01.
//

#ifndef CAR_CARPROPERTYFINDER_H
#define CAR_CARPROPERTYFINDER_H

#include "CarMovement.h"
#include "Scaner.h"

class CarPropertyFinder
{
	// mediator of class CarMovement & InstrumentErrorCorrection
public:
	Car car;
	CarMovement carMovement;
	Scaner scaner;
public:
	CarPropertyFinder(Car &car, const CarMovement &carMovement, const Scaner &scaner) :
			car(car), carMovement(carMovement), scaner(scaner) {}

public:
	double findCarRPS(int hexSpeed = 10); // Revolutions Per Second
	double findCarWidth();
	double findScanerDistance();
};

#endif //CAR_CARPROPERTYFINDER_H
