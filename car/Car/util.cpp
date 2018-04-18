//
// Created by Administrator on 2018-04-15.
//

#include "util.h"
using namespace joey_utility;
#include <Arduino.h>

#define PI 3.14159265

template <typename T>
T joey_utility::toRadian(T degree) {
	return degree * PI / 180;
}

double joey_utility::toDegree(double radian) {
	return radian * 180 / PI;
}

double joey_utility::map2Hex(double value, double fromLow, double fromHigh) {
	return map(value, fromLow, fromHigh, 0, 255);
}

double joey_utility::mapFromHex(double value, double toLow, double toHigh) {
	return map(value, 0, 255, toLow, toHigh);
}

