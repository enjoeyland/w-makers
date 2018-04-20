//
// Created by Administrator on 2018-04-20.
//

#ifndef CAR_INSTRUMENTERRORCORRECTION_H
#define CAR_INSTRUMENTERRORCORRECTION_H

#include "CarMovement.h"
#include "Scaner.h"


class InstrumentErrorCorrection
{
	// error correction of DC motor, Servo motor

public:
	CarMovement mCarMovement;
	Scaner mScaner;

public:
//	InstrumentErrorCorrection();
	InstrumentErrorCorrection(CarMovement carMovement, Scaner scaner):
			mCarMovement(carMovement),
			Scaner(scaner) {}
	~InstrumentErrorCorrection();

public:
	double findMotorRPS(); // Resolution Per Second
};

#endif //CAR_INSTRUMENTERRORCORRECTION_H
