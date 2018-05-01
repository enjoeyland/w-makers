//
// Created by Administrator on 2018-04-15.
//

#ifndef CAR_UTILITY_H
#define CAR_UTILITY_H

#include <Arduino.h>

#define PI 3.14159265


namespace joey_utility {
	inline double toRadian(double degree){
		return degree * (PI / (double)180);
	}

	inline double toDegree(double radian){
		return radian * 180 / PI;
	}

	inline long map2Hex(double value, double fromLow, double fromHigh){
		return map((long)value, (long)fromLow, (long)fromHigh, (long) 0, (long) 255);
	}

	inline long mapFromHex(double value, double toLow, double toHigh){
		return map((long)value, (long)0, (long)255, (long)toLow, (long)toHigh);
	}

}
#endif //CAR_UTILITY_H
