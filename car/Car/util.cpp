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

float joey_utility::toDegree(float radian) {
	return radian * 180 / PI;
}

float joey_utility::map2Hex(float value, float fromLow, float fromHigh) {
	return map(value, fromLow, fromHigh, 0, 255);
}

float joey_utility::mapFromHex(float value, float toLow, float toHigh) {
	return map(value, 0, 255, toLow, toHigh);
}

