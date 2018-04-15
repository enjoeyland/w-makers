//
// Created by Administrator on 2018-04-15.
//

#ifndef CAR_UTILITY_H
#define CAR_UTILITY_H

namespace joey_utility {
	template <typename T>
	inline T toRadian(T degree);
	inline float toDegree(float radian);
	inline float map2Hex(float value, float fromLow, float fromHigh);
	inline float mapFromHex(float value, float toLow, float toHigh);
}
#endif //CAR_UTILITY_H
