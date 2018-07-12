#include "CarMovement.h"

// TODO : CarMovement의 speed 를 HexSpeed 와 진짜speed로 구분하기

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
	auto intHexSpeed = (int) hexSpeed;
	setMotorSpeed(intHexSpeed, intHexSpeed);

	//	오차 보정
	double diff = hexSpeed - intHexSpeed;
	currentMovingError = {GO_FORWARD, intHexSpeed, intHexSpeed, diff, diff};

	if (distance) {
		delay(static_cast<unsigned long>(speed / distance * 1000));
		stop();
	}
}

void CarMovement::goBackward (double hexSpeed, double distance) {
	double speed = getRpsSpeed(hexSpeed);
	auto intHexSpeed = (int) hexSpeed;
	setMotorSpeed(-intHexSpeed, -intHexSpeed);

	//	오차 보정
	double diff = hexSpeed - intHexSpeed;
	currentMovingError = {GO_BACKWARD, intHexSpeed, intHexSpeed, diff, diff};

	if (distance) {
		delay(static_cast<unsigned long>(speed / distance * 1000));
		stop();
	}
}

void CarMovement::stop () {
	setMotorSpeed(0, 0);
}


// 회전
// '라디안'이 아니라 '도'로
void CarMovement::turnLeft	(double average_hexSpeed,  double radius,  double degree) {
	double averageSpeed = getRpsSpeed(average_hexSpeed);
	double angularSpeed = getAngularSpeed(averageSpeed, radius);
	double leftSpeed = angularSpeed * radius;
	double rightSpeed = angularSpeed * (radius + car.width);

	int intLeftHexSpeed, intRightHexSpeed;
	setMotorSpeed(intLeftHexSpeed, intRightHexSpeed);

	//	오차 보정
	double leftDiff = leftHexSpeed - intLeftHexSpeed;
	double rightDiff = rightHexSpeed - intRightHexSpeed;
	currentMovingError = {TURN_LEFT, intLeftHexSpeed, intRightHexSpeed, leftDiff, rightDiff};

	if (degree){
		turnSpecificDegree(angularSpeed, degree);
	}
}

void CarMovement::turnRight	(double average_hexSpeed, double radius, double degree){
	double averageSpeed = getRpsSpeed(average_hexSpeed);
	double angularSpeed = getAngularSpeed(averageSpeed, radius);
	double leftSpeed = angularSpeed * (radius + car.width);
	double rightSpeed = angularSpeed * radius;

	int intLeftHexSpeed, intRightHexSpeed;
	setMotorSpeed(intLeftHexSpeed, intRightHexSpeed);

	//	오차 보정
	double leftDiff = leftHexSpeed - intLeftHexSpeed;
	double rightDiff = rightHexSpeed - intRightHexSpeed;
	currentMovingError = {TURN_RIGHT, intLeftHexSpeed, intRightHexSpeed, leftDiff, rightDiff};

	if (degree){
		turnSpecificDegree(angularSpeed, degree);
	}
}

// 제자리리에서 회전
void CarMovement::spinLeft (double average_hexSpeed, double radius, double degree){
	double averageSpeed = getRpsSpeed(average_hexSpeed);
	double angularSpeed = getAngularSpeed(averageSpeed, radius);
	double leftSpeed = angularSpeed * (radius + car.width / 2);
	double rightSpeed = angularSpeed * (radius - car.width / 2);

	int intLeftHexSpeed, intRightHexSpeed;
	setMotorSpeed(intLeftHexSpeed, intRightHexSpeed);

	//	오차 보정
	double leftDiff = leftHexSpeed - intLeftHexSpeed;
	double rightDiff = rightHexSpeed - intRightHexSpeed;
	currentMovingError = {SPIN_LEFT, intLeftHexSpeed, intRightHexSpeed, leftDiff, rightDiff};

	if (degree){
		turnSpecificDegree(angularSpeed, degree);
	}
}

void CarMovement::spinRight	(double average_hexSpeed, double radius, double degree){
	double averageSpeed = getRpsSpeed(average_hexSpeed);
	double angularSpeed = getAngularSpeed(averageSpeed, radius);
	double leftSpeed = angularSpeed * (radius - car.width / 2);
	double rightSpeed = angularSpeed * (radius + car.width / 2);


	int intLeftHexSpeed, intRightHexSpeed;
	setMotorSpeed(intLeftHexSpeed, intRightHexSpeed);

	//	오차 보정
	double leftDiff = leftHexSpeed - intLeftHexSpeed;
	double rightDiff = rightHexSpeed - intRightHexSpeed;
	currentMovingError = {SPIN_RIGHT, intLeftHexSpeed, intRightHexSpeed, leftDiff, rightDiff};

	if (degree){
		turnSpecificDegree(angularSpeed, degree);
	}
}


//CarMoveAnalog
void CarMovementAnalog::setMotorSpeed(int leftHexSpeed, int rightHexSpeed) {
	if (leftHexSpeed >= 0) {
		analogWrite(static_cast<uint8_t>(pin_LeftMotor_go), leftHexSpeed);
		analogWrite(static_cast<uint8_t>(pin_leftMotor_back), 0);
	} else {
		analogWrite(static_cast<uint8_t>(pin_LeftMotor_go), 0);
		analogWrite(static_cast<uint8_t>(pin_leftMotor_back), -leftHexSpeed);
	}

	if (rightHexSpeed  >= 0) {
		analogWrite(static_cast<uint8_t>(pin_rightMotor_go), rightHexSpeed);
		analogWrite(static_cast<uint8_t>(pin_rightMotor_back), 0);
	} else {
		analogWrite(static_cast<uint8_t>(pin_rightMotor_go), 0);
		analogWrite(static_cast<uint8_t>(pin_rightMotor_back), -rightHexSpeed);
	}
}

// CarMovementDigital
void CarMovementDigital::setMotorSpeed(int leftHexSpeed, int rightHexSpeed) {
	if (leftHexSpeed >= 0) {
		digitalWrite(static_cast<uint8_t>(pin_LeftMotor_go), HIGH);
		digitalWrite(static_cast<uint8_t>(pin_leftMotor_back), LOW);
	} else {
		digitalWrite(static_cast<uint8_t>(pin_LeftMotor_go), LOW);
		digitalWrite(static_cast<uint8_t>(pin_leftMotor_back), HIGH);
	}

	if (rightHexSpeed  >= 0) {
		digitalWrite(static_cast<uint8_t>(pin_rightMotor_go), HIGH);
		digitalWrite(static_cast<uint8_t>(pin_rightMotor_back), LOW);
	} else {
		digitalWrite(static_cast<uint8_t>(pin_rightMotor_go), LOW);
		digitalWrite(static_cast<uint8_t>(pin_rightMotor_back), HIGH);
	}
}
