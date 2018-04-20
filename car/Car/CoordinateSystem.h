//
// Created by Administrator on 2018-04-15.
//

#ifndef CAR_COORDINATESYSTEM_H
#define CAR_COORDINATESYSTEM_H

namespace coordinateSystem {
	template <typename T>
	class RectangularPoint;

	template <typename T>
	class PolarPoint
	{
	public:
		T degree;
		T radialDistance;

	public:
		PolarPoint(): degree(0), radialDistance(0), correspondingRP_Defined(false) {}
		PolarPoint(T _degree, T _radialDistance):
				degree(_degree),
				radialDistance(_radialDistance),
				correspondingRP_Defined(false) {}
		~PolarPoint();

	public:
		void SetInfo(T _degree, T _radialDistance);
		RectangularPoint<T> toRectangular();
		void move(T x, T y);
		void modifyDegree(T _degree);
		void modifyRadialDistance(T _radialDistance);

	private:
		RectangularPoint<T> correspondingRP;
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
		void SetInfo(T x, T y);
		RectangularPoint operator+ (const RectangularPoint &RP);
		PolarPoint<T> toPolar();
		void move(T x, T y);

	private:
		PolarPoint<T> correspondingPP;
		bool correspondingRP_Defined;
	};
}


#endif //CAR_COORDINATESYSTEM_H
