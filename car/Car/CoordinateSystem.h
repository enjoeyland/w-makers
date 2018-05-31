//
// Created by Enjoeyland on 2018-04-15.
//

#ifndef CAR_COORDINATESYSTEM_H
#define CAR_COORDINATESYSTEM_H

namespace coordinateSystem {
	class RectangularPoint;

	class PolarPoint
	{
	public:
		double degree;
		double radialDistance;

	public:
		PolarPoint();
		PolarPoint(double _degree, double _radialDistance);

	public:
		void SetInfo(double _degree, double _radialDistance);
		RectangularPoint* toRectangular();
		void move(double x, double y);
		void modifyDegree(double _degree);
		void modifyRadialDistance(double _radialDistance);

	private:
		RectangularPoint *correspondingRP;
		bool correspondingRP_Defined;
	};


	class RectangularPoint
	{
	public:
		double x;
		double y;

	public:
		RectangularPoint(): x(0), y(0), correspondingRP_Defined(false), correspondingPP(new PolarPoint()) {}
		RectangularPoint(double x, double y): x(x), y(y), correspondingRP_Defined(false), correspondingPP(new PolarPoint()) {}

	public:
		void SetInfo(double x, double y);
		RectangularPoint operator+ (const RectangularPoint &rectangularPoint);
		RectangularPoint operator- (const RectangularPoint &rectangularPoint);
		bool operator== (const RectangularPoint &rectangularPoint);
		PolarPoint* toPolar();
		void move(double x, double y);

	private:
		PolarPoint *correspondingPP;
		bool correspondingRP_Defined;
	};


	class Line
	{
	public:
		RectangularPoint startPoint;
		RectangularPoint endPoint;
		double length;
		double degree;

	public:
		Line(RectangularPoint startPoint, RectangularPoint endPoint);
		explicit Line(RectangularPoint endPoint) : Line(RectangularPoint(),endPoint) {}

	public:
		RectangularPoint getMiddlePoint();
		bool operator== (const Line &line);

	protected:
		void calculateLength();
		void calculateDegree();
	};


	class D2Vector : public Line {
		// can operate +/-
	public:
		explicit D2Vector(RectangularPoint point): Line(point){}

	public:
		D2Vector operator+(const D2Vector &d2Vector);
		D2Vector operator-(const D2Vector &d2Vector);
	};
}


#endif //CAR_COORDINATESYSTEM_H
