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
			bigChangeList[j] =  lineList[i];
			j++;
		}
	}
}

void ScanDataAnalyst::findGap() {
	// todo : need improve really and a lot
	int k = 0;
	for (int i=0; i < sizeof(bigChangeList)/ sizeof(bigChangeList[0]); i++){
		for (int j =0; j < scanDataLen - 1; j++) {
			if (lineList[j] == bigChangeList[i]) {
				double gapSize;
				double diffDegree;
				RectangularPoint gapCriterion;
				Line * gap;
				if (Line(bigChangeList[i].endPoint).length - Line(bigChangeList[i].startPoint).length >= 0) {
					diffDegree = lineList[j-1].degree- bigChangeList[i].degree;
					gapSize = bigChangeList[i].length * sin(diffDegree);
					gapCriterion = bigChangeList[i].endPoint;
					gap = new Line(*PolarPoint(lineList[j-1].degree- 270, gapSize).toRectangular()+ gapCriterion, gapCriterion);

				} else {
					diffDegree = bigChangeList[i].degree - lineList[j+1].degree;
					gapSize = bigChangeList[i].length * sin(diffDegree);
					gapCriterion = bigChangeList[i].startPoint;
					gap = new Line(gapCriterion, *PolarPoint(90 + lineList[j+1].degree,gapSize).toRectangular() + gapCriterion);
				}
				if (gapSize >= gapMin) {
					gapList[k] = *gap;
					k++;
				}
			}
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






