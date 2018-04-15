//
// Created by Administrator on 2018-04-15.
//

#include "utility.h"
using namespace joey_utility;

#define PI 3.14159265

float joey_utility::toRadian() {
	return degree * PI / 180;
}

float joey_utility::map2Hex(float value, float fromLow, float fromHigh) {
	return map(value, fromLow, fromHigh, 0, 255);
}

float joey_utility::mapFromHex(float value, float toLow, float toHigh) {
	return map(value, 0, 255, toLow, toHigh);
}

