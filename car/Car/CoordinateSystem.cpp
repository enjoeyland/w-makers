//
// Created by Administrator on 2018-04-15.
//

#include "CoordinateSystem.h"
#include "util.h"
#include <cmath>
using joey_utility::toRadian;
using joey_utility::toDegree;

namespace coordinateSystem {
	// defining PolarPoint
	PolarPoint::PolarPoint() : degree(0), radialDistance(0), correspondingRP_Defined(false), correspondingRP(new RectangularPoint())  {

	}

	PolarPoint::PolarPoint(double _degree, double _radialDistance) :
			degree(_degree),
			radialDistance(_radialDistance),
			correspondingRP_Defined(false),
			correspondingRP(new RectangularPoint()) {}

	void PolarPoint::SetInfo(double _degree, double _radialDistance) {
		this->degree = _degree;
		this->radialDistance = _radialDistance;
	}

	RectangularPoint* PolarPoint::toRectangular() {
		if (correspondingRP_Defined) {
			return correspondingRP;
		} else {
			correspondingRP->x = radialDistance * cos(toRadian(degree));
			correspondingRP->y = radialDistance * sin(toRadian(degree));
			correspondingRP_Defined = true;
			return correspondingRP;
		}
	}

	void PolarPoint::move(double x, double y) {
		toRectangular();
		correspondingRP->move(x, y);
		degree = correspondingRP->toPolar()->degree;
		radialDistance = correspondingRP->toPolar()->radialDistance;

	}

	void PolarPoint::modifyDegree(double _degree) {
		this->degree += _degree;
	}

	void PolarPoint::modifyRadialDistance(double _radialDistance) {
		this->radialDistance += _radialDistance;
	}



	// defining RectangularPoint
	void RectangularPoint::SetInfo(double x, double y) {
		this->x = x;
		this->y = y;
	}

	RectangularPoint RectangularPoint::operator+(const coordinateSystem::RectangularPoint &rectangularPoint) {
		RectangularPoint resultRP;
		resultRP.x = this->x + rectangularPoint.x;
		resultRP.y = this->y + rectangularPoint.y;
		return resultRP;
	}

	RectangularPoint RectangularPoint::operator-(const coordinateSystem::RectangularPoint &rectangularPoint) {
		RectangularPoint resultRP;
		resultRP.x = this->x - rectangularPoint.x;
		resultRP.y = this->y - rectangularPoint.y;
		return resultRP;
	}

	bool RectangularPoint::operator==(const RectangularPoint &rectangularPoint) {
		return this->x == rectangularPoint.x && this->y == rectangularPoint.y);
	}

	PolarPoint* RectangularPoint::toPolar() {
		if (correspondingRP_Defined) {
			return correspondingPP;
		} else {
			correspondingPP->radialDistance = sqrt(pow(x, 2) + pow(y, 2));
			correspondingPP->degree = toDegree(acos(correspondingPP->radialDistance));
			correspondingRP_Defined = true;
			return correspondingPP;
		}
	}

	void RectangularPoint::move(double x, double y) {
		this->x += x;
		this->y += y;
	}



	// defining Line Class
	Line::Line(RectangularPoint startPoint, RectangularPoint endPoint): startPoint(startPoint),endPoint(endPoint) {
		calculateLength();
		calculateDegree();
	}

	RectangularPoint Line::getMiddlePoint() {
		double midX = (this->startPoint.x + this->endPoint.x) / 2;
		double midY = (this->startPoint.y + this->endPoint.y) / 2;
		return RectangularPoint{midX, midY};
	}

	bool Line::operator==(const Line &line) {
		return this->startPoint == line.startPoint && this->endPoint == line.endPoint;
	}

	void Line::calculateLength() {
		this->length = (double) sqrt(pow(startPoint.x - endPoint.x, 2) + pow(startPoint.y - endPoint.y, 2));
	}

	void Line::calculateDegree() {
		this->degree = toDegree(atan((startPoint.y - endPoint.y) / (startPoint.x - endPoint.x)));
	}

	// defining D2Vector Class
	D2Vector D2Vector::operator+(const coordinateSystem::D2Vector &d2Vector) {
		return D2Vector{this->endPoint + d2Vector.endPoint};
	}

	D2Vector D2Vector::operator-(const coordinateSystem::D2Vector &d2Vector) {
		return D2Vector{this->endPoint - d2Vector.endPoint};
	}
}
