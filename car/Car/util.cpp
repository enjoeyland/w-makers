//
// Created by Administrator on 2018-04-15.
//

#include "util.h"
using namespace joey_utility;
#include <Arduino.h>

#define PI 3.14159265

template <typename T>
T joey_utility::toRadian(T degree) {
	return (T) degree * (PI / (double)180);
}

double joey_utility::toDegree(double radian) {
	return radian * 180 / PI;
}

double joey_utility::map2Hex(double value, double fromLow, double fromHigh) {
	return (double) map((long)value, (long)fromLow, (long)fromHigh, (long) 0, (long) 255);
}

double joey_utility::mapFromHex(double value, double toLow, double toHigh) {
	return (double) map((long)value, (long)0, (long)255, (long)toLow, (long)toHigh);
}

