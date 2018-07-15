//
// Created by Administrator on 2018-05-01.
//

#ifndef CAR_SCANDATAANALYST_H
#define CAR_SCANDATAANALYST_H

#include "CoordinateSystem.h"
using coordinateSystem::PolarPoint;
using coordinateSystem::Line;
using coordinateSystem::RectangularPoint;

class ScanDataAnalyst
{
public:
	Line lineList[];
	int bigChangeList[];
	Line gapList[];
	int scanDataLen;
	int groupList[];
public:
	explicit ScanDataAnalyst(PolarPoint* scanData, double gapMin);
	~ScanDataAnalyst();

public:
	void findAll();
	void makeLineList();
	void findBigChange();   // consider Line bigger than BigchangeMin as BigChange
												// BigChange can be consider as gap
												// need pre-call of makeLineList
	void findGap(); // need pre-call of findBigChange
	void findGroup(double allowableError); // 비슷한 degree grouping

protected:
	PolarPoint* scanData;
	double gapMin;
};

#endif //CAR_SCANDATAANALYST_H
