#include "CarMovement.h"
#include "util.h"
#include <Arduino.h>
using namespace joey_utility;

// TODO : CarMovement의 speed 를 HexSpeed 와 진짜speed로 구분하기
// todo : speed값을 0~255에 맞도록 수정 해야 될거 같다.

//namespace carMovement {

// CarMovement
CarMovement::CarMovement(int *dcMotorPins, Car car) :
		pin_LeftMotor_go(dcMotorPins[0]),
		pin_leftMotor_back(dcMotorPins[1]),
		pin_rightMotor_go(dcMotorPins[2]),
		pin_rightMotor_back(dcMotorPins[3]),
		car(car) {}

// 앞으로, 뒤로
void CarMovement::goForward	(double hexSpeed, double distance){
	double speed = getRpsSpeed(hexSpeed);
	int intHexSpeed = (int) hexSpeed; // todo : auto 아두이노 에서 되는지 확인하고 쓰기
	setMotorSpeed(intHexSpeed, intHexSpeed);

	double diff = hexSpeed - intHexSpeed;
	currentMovingError = {GO_FORWARD, intHexSpeed, intHexSpeed, diff, diff};

	if (distance) {
		delay(speed / distance * 1000);
		stop();
	}
}

void CarMovement::goBackward (double hexSpeed, double distance) {
	double speed = getRpsSpeed(hexSpeed);
	setMotorSpeed(-hexSpeed, -hexSpeed);
	if (distance) {
		delay(speed / distance * 1000);
		stop();
	}
}

void CarMovement::stop () {
	setMotorSpeed(0, 0);
}


// 회전
// '라디안'이 아니라 '도'로
void CarMovement::turnLeft	(double average_hexSpeed,  double radius,  double degree= 0) {
	double averageSpeed = getRpsSpeed(average_hexSpeed);
	double angularSpeed = getAngularSpeed(averageSpeed, radius);
	double leftSpeed = angularSpeed * radius;
	double rightSpeed = angularSpeed * (radius + car.width);

	setMotorSpeed(leftHexSpeed, rightHexSpeed);

	if (degree){
		turnSpecificDegree(angularSpeed, degree);
	}
}

void CarMovement::turnRight	(double average_hexSpeed, double radius, double degree = 0){
	double averageSpeed = getRpsSpeed(average_hexSpeed);
	double angularSpeed = getAngularSpeed(averageSpeed, radius);
	double leftSpeed = angularSpeed * (radius + car.width);
	double rightSpeed = angularSpeed * radius;

	setMotorSpeed(leftHexSpeed, rightHexSpeed);

	if (degree){
		turnSpecificDegree(angularSpeed, degree);
	}
}

// 제자리리에서 회전
void CarMovement::spinLeft (double average_hexSpeed, double radius, double degree = 0){
	double averageSpeed = getRpsSpeed(average_hexSpeed);
	double angularSpeed = getAngularSpeed(averageSpeed, radius);
	double leftSpeed = angularSpeed * (radius + car.width / 2);
	double rightSpeed = angularSpeed * (radius - car.width / 2);

	setMotorSpeed(leftHexSpeed, rightHexSpeed);

	if (degree){
		turnSpecificDegree(angularSpeed, degree);
	}
}

void CarMovement::spinRight	(double average_hexSpeed, double radius, double degree = 0){
	double averageSpeed = getRpsSpeed(average_hexSpeed);
	double angularSpeed = getAngularSpeed(averageSpeed, radius);
	double leftSpeed = angularSpeed * (radius - car.width / 2);
	double rightSpeed = angularSpeed * (radius + car.width / 2);


	setMotorSpeed(leftHexSpeed, rightHexSpeed);

	if (degree){
		turnSpecificDegree(angularSpeed, degree);
	}
}


//CarMoveAnalog
void CarMovementAnalog::setMotorSpeed(int leftHexSpeed, int rightHexSpeed) {
	if (leftHexSpeed >= 0) {
		analogWrite(pin_LeftMotor_go, leftHexSpeed);
		analogWrite(pin_leftMotor_back, 0);
	} else {
		analogWrite(pin_LeftMotor_go, 0);
		analogWrite(pin_leftMotor_back, -leftHexSpeed);
	}

	if (rightHexSpeed  >= 0) {
		analogWrite(pin_rightMotor_go, rightHexSpeed);
		analogWrite(pin_rightMotor_back, 0);
	} else {
		analogWrite(pin_rightMotor_go, 0);
		analogWrite(pin_rightMotor_back, -rightHexSpeed);
	}
}

// CarMovementDigital
void CarMovementDigital::setMotorSpeed(int leftHexSpeed, int rightHexSpeed) {
	if (leftHexSpeed >= 0) {
		digitalWrite(pin_LeftMotor_go, HIGH);
		digitalWrite(pin_leftMotor_back, LOW);
	} else {
		digitalWrite(pin_LeftMotor_go, LOW);
		digitalWrite(pin_leftMotor_back, HIGH);
	}

	if (rightHexSpeed  >= 0) {
		digitalWrite(pin_rightMotor_go, HIGH);
		digitalWrite(pin_rightMotor_back, LOW);
	} else {
		digitalWrite(pin_rightMotor_go, LOW);
		digitalWrite(pin_rightMotor_back, HIGH);
	}
}
