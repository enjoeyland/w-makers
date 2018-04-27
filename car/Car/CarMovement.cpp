#include "CarMovement.h"
#include <Arduino.h>

// TODO : CarMovement의 speed 를 HexSpeed 와 진짜speed로 구분하기
// todo : speed값을 0~255에 맞도록 수정 해야 될거 같다.

//namespace carMovement {

// CarMovement
CarMovement::CarMovement(
		int pin_left_motor_go,
		int pin_left_motor_back,
		int pin_right_motor_go,
		int pin_right_motor_back,
		double car_width) :
		pin_left_motor_go(pin_left_motor_go),
		pin_left_motor_back(pin_left_motor_back),
		pin_right_motor_go(pin_right_motor_go),
		pin_right_motor_back(pin_right_motor_back),
		car_width(car_width) {}

// 앞으로, 뒤로
void CarMovement::goForward	(const double &speed, double distance){
	setMotorSpeed(speed, speed);
	if (distance) {
		delay(speed / distance * 1000);
		stop();
	}
}

void CarMovement::goBackward	(const double &speed, double distance) {
	setMotorSpeed(-speed, -speed);
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
void CarMovement::turnLeft	(const double &average_speed, const double &radius, const double &degree= 0) {
	double angular_speed = getAngularSpeed(average_speed, radius);
	double right_speed = angular_speed * (radius + car_width);
	double left_speed = angular_speed * radius;

	setMotorSpeed(right_speed, left_speed);

	if (degree){
		turnSpecificDegree(angular_speed, degree);
	}
}

void CarMovement::turnRight	(const double &average_speed, const double &radius, const double &degree = 0){
	double angular_speed = getAngularSpeed(average_speed, radius);
	double right_speed = angular_speed * radius;
	double left_speed = angular_speed * (radius + car_width);

	setMotorSpeed(right_speed, left_speed);

	if (degree){
		turnSpecificDegree(angular_speed, degree);
	}
}


// 제자리리에서 회전
void CarMovement::spinLeft	(const double &average_speed, const double &radius, const double &degree = 0){
	double angular_speed = getAngularSpeed(average_speed, radius);
	double right_speed = angular_speed * (radius - car_width);
	double left_speed = angular_speed * (radius + car_width);

	setMotorSpeed(right_speed, left_speed);

	if (degree){
		turnSpecificDegree(angular_speed, degree);
	}
}

void CarMovement::spinRight	(const double &average_speed, const double &radius, const double &degree = 0){
	double angular_speed = getAngularSpeed(average_speed, radius);
	double right_speed = angular_speed * (radius + car_width);
	double left_speed = angular_speed * (radius - car_width);

	setMotorSpeed(right_speed, left_speed);

	if (degree){
		turnSpecificDegree(angular_speed, degree);
	}
}

//CarMoveAnalog
void CarMovementAnalog::setMotorSpeed(const double &right_speed, const double &left_speed) {
	if (right_speed  >= 0) {
		analogWrite(pin_right_motor_go, right_speed);
		analogWrite(pin_right_motor_back, 0);
	} else {
		analogWrite(pin_right_motor_go, 0);
		analogWrite(pin_right_motor_back, -right_speed);
	}
	if (left_speed >= 0) {
		analogWrite(pin_left_motor_go, left_speed);
		analogWrite(pin_left_motor_back, 0);
	} else {
		analogWrite(pin_left_motor_go, 0);
		analogWrite(pin_left_motor_back, -left_speed);
	}
}

// CarMovementDigital
void CarMovementDigital::setMotorSpeed(const double &right_speed, const double &left_speed) {
	if (right_speed  >= 0) {
		digitalWrite(pin_right_motor_go, HIGH);
		digitalWrite(pin_right_motor_back, LOW);
	} else {
		digitalWrite(pin_right_motor_go, LOW);
		digitalWrite(pin_right_motor_back, HIGH);
	}
	if (left_speed >= 0) {
		digitalWrite(pin_left_motor_go, HIGH);
		digitalWrite(pin_left_motor_back, LOW);
	} else {
		digitalWrite(pin_left_motor_go, LOW);
		digitalWrite(pin_left_motor_back, HIGH);
	}
}
//}