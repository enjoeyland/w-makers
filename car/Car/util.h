//
// Created by Administrator on 2018-04-15.
//

#ifndef CAR_UTILITY_H
#define CAR_UTILITY_H

namespace joey_utility {
	template <typename T>
	inline T toRadian(T degree);
	inline double toDegree(double radian);
	inline double map2Hex(double value, double fromLow, double fromHigh);
	inline double mapFromHex(double value, double toLow, double toHigh);
}
#endif //CAR_UTILITY_H
