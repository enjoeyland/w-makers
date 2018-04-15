//
// Created by Administrator on 2018-04-15.
//

#include "CoordinateSystem.h"
#include "util.h"
#include <math.h>
using joey_utility::toRadian;
using joey_utility::toDegree;
using namespace coordinateSystem;


// defining PolarPoint
RectangularPoint PolarPoint::toRectangular() {
	if (correspondingRP_Defined) {
		return correspondingRP;
	} else {
		correspondingRP.x = radial_distance * cos(toRadian<T>(degree));
		correspondingRP.y = radial_distance * sin(toRadian<T>(degree));
		correspondingRP_Defined = true;
		return correspondingRP;
	}
}

void PolarPoint::move(T x, T y) {
	toRectangular();
	correspondingRP.move(x, y);
	degree = correspondingRP.toPolar().degree;
	radial_distance = correspondingRP.toPolar().radial_distance;
}

void PolarPoint::modifyDegree(T degree) {
	this->degree += degree;
}

void PolarPoint::modifyRadialDistance(T radial_distance) {
	this->radial_distance += radial_distance;
}


// defining RectangularPoint
PolarPoint RectangularPoint::toPolar() {
	if (correspondingRP_Defined) {
		return correspondingPP;
	} else {
		correspondingPP.radial_distance = sqrt(2, pow(x, 2) + pow(y, 2));
		correspondingPP.degree = toDegree(acos(correspondingPP.radial_distance));
		correspondingRP_Defined = true;
		return correspondingPP;
	}
}

void RectangularPoint::move(T x, T y) {
	this->x += x;
	this->y += y;
}

