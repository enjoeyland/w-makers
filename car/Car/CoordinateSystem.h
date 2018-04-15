//
// Created by Administrator on 2018-04-15.
//

#ifndef CAR_COORDINATESYSTEM_H
#define CAR_COORDINATESYSTEM_H

namespace coordinateSystem {
	class RectangularPoint;

	template <typename T>
	class PolarPoint
	{
	public:
		T degree;
		T radial_distance;

	public:
		PolarPoint(): degree(0), radial_distance(0), correspondingRP_Defined(false) {}
		PolarPoint(T degree, T radial_distance): degree(degree), radial_distance(radial_distance), correspondingRP_Defined(
				false) {}
		~PolarPoint();

	public:
		RectangularPoint toRectangular();
		void move(T x, T y);
		void modifyDegree(T degree);
		void modifyRadialDistance(T radial_distance);

	private:
		RectangularPoint correspondingRP;
		bool correspondingRP_Defined;
	};


	template <typename T>
	class RectangularPoint
	{
	public:
		T x;
		T y;

	public:
		RectangularPoint(): x(0), y(0), correspondingRP_Defined(false) {}
		RectangularPoint(T x, T y): x(x), y(y), correspondingRP_Defined(false) {}
		~RectangularPoint();

	public:
		PolarPoint toPolar();
		void move(T x, T y);

	private:
		PolarPoint correspondingPP;
		bool correspondingRP_Defined;
	};
}


#endif //CAR_COORDINATESYSTEM_H
