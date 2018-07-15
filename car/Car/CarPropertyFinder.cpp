//
// Created by Administrator on 2018-05-01.
//

#include "CarPropertyFinder.h"
#include "ScanDataAnalyst.h"
#include <Arduino.h>

double CarPropertyFinder::findCarRPS(int hexSpeed) {
	// Revolutions Per Second
	double beforeDistance = scaner->measureDistance();
	carMovement->goForward(hexSpeed, 0);
	delay(2000);
	carMovement->stop();
	double afterDistance = scaner->measureDistance();
	double averageRPS = (afterDistance - beforeDistance) / (double) hexSpeed;
	return averageRPS;
}

double CarPropertyFinder::findCarWidth() {
	ScanDataAnalyst scanDataAnalyst(scaner->scan180(), car.width);
	int* gl = scanDataAnalyst.groupList;
	// group list 중 가장 item이 많은 것을 기준으로 잡기
	// 기준의 법선 기울기를 구하기 (벽쪽 방향으로)
	// 법선 기울기로 차의 기울기 맞추기 (오차 발생)
	// 스캔하기 2
	// 법선 기울기 찾기
	// 넓이 구하기(기대 기울기 - 법선 기울기)
	// return 넓이
	return 0;
}

double CarPropertyFinder::findScanerDistance() {
	// 스캔하기
	// 스캔 데이터 분석
	// group list 중 가장 item이 많은 것을 기준으로 잡기
	// 기준의 법선 기울기를 구하기 (벽쪽 방향으로)
	// 법선 기울기로 차의 기울기 맞추기
	// 거리측정 1
	// 기준의 기울기로 차의 기울기 맞추기
	// 볍선 기울기 바향으로 servo 기울기 맞추기
	// 거리측정 2
	// return 거리2- 거리 1
	return 0;
}
