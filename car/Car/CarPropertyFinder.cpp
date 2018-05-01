//
// Created by Administrator on 2018-05-01.
//

#include "CarPropertyFinder.h"
#include "CarMovement.h"
#include <Arduino.h>

double CarPropertyFinder::findCarRPS(int hexSpeed) {
	// Revolutions Per Second
	double beforeDistance = scaner.measureDistance();
	carMovement.goForward(hexSpeed);
	delay(2000);
	carMovement.stop();
	double afterDistance = scaner.measureDistance();
	double averageRPS = (afterDistance - beforeDistance) / (double) hexSpeed;
	return averageRPS;
}

double CarPropertyFinder::findCarWidth() {
	scaner.scan180();
//	scaner.g
	return 0;
}

double CarPropertyFinder::findScanerDistance() {
	return 0;
}
