//
// Created by Administrator on 2018-04-15.
//

#include "CoordinateSystem.h"
#include "util.h"
#include <math.h>
using joey_utility::toRadian;
using joey_utility::toDegree;

namespace coordinateSystem {
	// defining PolarPoint
	template<typename T>
	void PolarPoint<T>::SetInfo(T _degree, T _radialDistance) {
		this->degree = _degree;
		this->radialDistance = _radialDistance;
	}

	template <typename T>
	RectangularPoint<T> PolarPoint<T>::toRectangular() {
		if (correspondingRP_Defined) {
			return correspondingRP;
		} else {
			correspondingRP.x = radialDistance * cos(toRadian<T>(degree));
			correspondingRP.y = radialDistance * sin(toRadian<T>(degree));
			correspondingRP_Defined = true;
			return correspondingRP;
		}
	}

	template <typename T>
	void PolarPoint<T>::move(T x, T y) {
		toRectangular();
		correspondingRP.move(x, y);
		degree = correspondingRP.toPolar().degree;
		radialDistance = correspondingRP.toPolar().radialDistance;
	}

	template <typename T>
	void PolarPoint<T>::modifyDegree(T _degree) {
		this->degree += _degree;
	}

	template <typename T>
	void PolarPoint<T>::modifyRadialDistance(T _radialDistance) {
		this->radialDistance += _radialDistance;
	}


	// defining RectangularPoint
	template<typename T>
	void RectangularPoint<T>::SetInfo(T x, T y) {
		this->x = x;
		this->y = y;
	}

	template<typename T>
	RectangularPoint RectangularPoint<T>::operator+(const coordinateSystem::RectangularPoint<T> &RP) {
		RectangularPoint resultRP;
		resultRP.x = this.x + RP.x;
		resultRP.y = this.y + RP.y;
		return resultRP;
	}

	template <typename T>
	PolarPoint<T> RectangularPoint<T>::toPolar() {
		if (correspondingRP_Defined) {
			return correspondingPP;
		} else {
			correspondingPP.radialDistance = sqrt(2, pow(x, 2) + pow(y, 2));
			correspondingPP.degree = toDegree(acos(correspondingPP.radialDistance));
			correspondingRP_Defined = true;
			return correspondingPP;
		}
	}

	template <typename T>
	void RectangularPoint<T>::move(T x, T y) {
		this->x += x;
		this->y += y;
	}
}
