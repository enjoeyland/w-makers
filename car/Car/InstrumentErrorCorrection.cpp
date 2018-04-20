//
// Created by Administrator on 2018-04-20.
//

#include "InstrumentErrorCorrection.h"

double InstrumentErrorCorrection::findMotorRPS() {
	// Resolution Per Second
	int hexSpeed = 10;

	double distanceFirst = mScaner.measureDistance();
	mCarMovement.goForward(10);
	delay(1000);
	mCarMovement.stop();
	double distanceSecond = mScaner.measureDistance();

	rps = (distanceSecond - distanceFirst) / 10;
	return rps;
}