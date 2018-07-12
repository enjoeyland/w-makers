//
// Created by Administrator on 2018-04-15.
//

#ifndef CAR_UTILITY_H
#define CAR_UTILITY_H

#include <Arduino.h>

//#define PI 3.14159265


namespace joey_utility {
	inline double toRadian(double degree){
		return degree * (PI / (double)180);
	}

	inline double toDegree(double radian){
		return radian * 180 / PI;
	}

	inline double convertScale (double value, double inMin, double inMax, double outMin, double outMax){
		return (value - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
	}

	inline double convertScale2Hex (double value, double inMin, double inMax){
		return convertScale(value, inMin, inMax, 0,  255);
	}

	inline double convertScaleFromHex(double value, double outMin, double outMax){
		return convertScale(value, 0, 255, outMin, outMax);
	}

}
#endif //CAR_UTILITY_H
