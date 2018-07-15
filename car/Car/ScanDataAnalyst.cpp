//
// Created by Administrator on 2018-05-01.
//

#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>

#include <cmath>
#include "ScanDataAnalyst.h"


ScanDataAnalyst::ScanDataAnalyst(PolarPoint *scanData, double gapMin) : scanData(scanData), gapMin(gapMin){
	scanDataLen = sizeof(scanData) / sizeof(scanData[0]);
}

ScanDataAnalyst::~ScanDataAnalyst() {
	delete [] lineList;
	delete [] bigChangeList;
	delete [] gapList;
}

void ScanDataAnalyst::findAll() {
	makeLineList();
	findBigChange();
	findGap();
}

void ScanDataAnalyst::makeLineList() {
	for (int i =0; i < scanDataLen - 1; i++) {
		lineList[i] = Line(*scanData[i].toRectangular(), *scanData[i+1].toRectangular());
	}
}

void ScanDataAnalyst::findBigChange() {
	int j = 0;
	for (int i =0; i < scanDataLen - 1; i++) {
		if (lineList[i].length >= gapMin) {
			bigChangeList[j] = i;
			j++;
		}
	}
}

void ScanDataAnalyst::findGap() {
	// todo : need improve really and a lot
	int k = 0;
	for (int i=0; i < sizeof(bigChangeList)/ sizeof(bigChangeList[0]); i++){
		double gapSize;
		double diffDegree;
		RectangularPoint gapCriterion;
		Line * gap;
		Line interLine = lineList[bigChangeList[i]];
		if (Line(interLine.endPoint).length - Line(interLine.startPoint).length >= 0) {
			diffDegree = lineList[bigChangeList[i]-1].degree- interLine.degree;
			gapSize = interLine.length * sin(diffDegree);
			gapCriterion = interLine.endPoint;
			gap = new Line(*PolarPoint(lineList[bigChangeList[i]-1].degree - 270, gapSize).toRectangular() + gapCriterion, gapCriterion);

		} else {
			diffDegree = interLine.degree - lineList[bigChangeList[i]+1].degree;
			gapSize = interLine.length * sin(diffDegree);
			gapCriterion = interLine.startPoint;
			gap = new Line(gapCriterion, *PolarPoint(90 + lineList[bigChangeList[i]+1].degree,gapSize).toRectangular() + gapCriterion);
		}
		if (gapSize >= gapMin) {
			gapList[k] = *gap;
			k++;
		}
	}
}

void ScanDataAnalyst::findGroup(double allowableError) {
	Line preLine = lineList[0];
	// list1
	for (int i= 0; i < scanDataLen -1; i++) {
		if (preLine.degree - lineList[i].degree <= allowableError) {
			// list2.append(i)
		} else {
			// list1.append(list2)
			// del list2 (초기화)
			// list2.append(i)
		}
	}
	// grouplist = list1.append(list2)
}






