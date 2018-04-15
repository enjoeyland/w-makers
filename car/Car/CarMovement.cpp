#include "CarMovement.h"
#include <Arduino.h>

// speed값을 0~255에 맞도록 수정 해야 될거 같다.

namespace carMovement {
	// CarMovement
	CarMovement::CarMovement(
			int pin_left_motor_go,
			int pin_left_motor_back,
			int pin_right_motor_go,
			int pin_right_motor_back,
			float car_width) :
			pin_left_motor_go(pin_left_motor_go),
			pin_left_motor_back(pin_left_motor_back),
			pin_right_motor_go(pin_right_motor_go),
			pin_right_motor_back(pin_right_motor_back),
			car_width(car_width) {}

	float CarMovement::getAngularSpeed(const float &average_speed, const float &radius){
		return 2 * average_speed / (2 * radius + car_width); // 각속도
	}


	void CarMovement::turnSpecificDegree(const float &angular_speed, const float &degree) {
		float angle_radian = degree * PI / 180;
		float delay_time = angle_radian / angular_speed;

		delay(delay_time * 1000);
		stop();
	}


	// 앞으로, 뒤로
	void CarMovement::goForward	(const float &speed, float distance){
		setMotorSpeed(speed, speed);
		if (distance) {
			delay(speed / distance * 1000);
			stop();
		}
	}

	void CarMovement::goBackward	(const float &speed, float distance) {
		setMotorSpeed(-speed, -speed);
		if (distance) {
			delay(speed / distance * 1000);
			stop();
		}
	}

	void CarMovement::stop (void) {
		setMotorSpeed(0, 0);
	}


	// 회전
	// '라디안'이 아니라 '도'로
	void CarMovement::turnLeft	(const float &average_speed, const float &radius, const float &degree= 0) {
		float angular_speed = getAngularSpeed(average_speed, radius);
		float right_speed = angular_speed * (radius + car_width);
		float left_speed = angular_speed * radius;

		setMotorSpeed(right_speed, left_speed);

		if (degree){
			turnSpecificDegree(angular_speed, degree);
		}
	}

	void CarMovement::turnRight	(const float &average_speed, const float &radius, const float &degree = 0){
		float angular_speed = getAngularSpeed(average_speed, radius);
		float right_speed = angular_speed * radius;
		float left_speed = angular_speed * (radius + car_width);

		setMotorSpeed(right_speed, left_speed);

		if (degree){
			turnSpecificDegree(angular_speed, degree);
		}
	}


	// 제자리리에서 회전
	void CarMovement::spinLeft	(const float &average_speed, const float &radius, const float &degree = 0){
		float angular_speed = getAngularSpeed(average_speed, radius);
		float right_speed = angular_speed * (radius - car_width);
		float left_speed = angular_speed * (radius + car_width);

		setMotorSpeed(right_speed, left_speed);

		if (degree){
			turnSpecificDegree(angular_speed, degree);
		}
	}

	void CarMovement::spinRight	(const float &average_speed, const float &radius, const float &degree = 0){
		float angular_speed = getAngularSpeed(average_speed, radius);
		float right_speed = angular_speed * (radius + car_width);
		float left_speed = angular_speed * (radius - car_width);

		setMotorSpeed(right_speed, left_speed);

		if (degree){
			turnSpecificDegree(angular_speed, degree);
		}
	}

	//CarMoveAnalog
	void CarMovementAnalog::setMotorSpeed(const float &right_speed, const float &left_speed) {
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
	void CarMovementDigital::setMotorSpeed(const float &right_speed, const float &left_speed) {
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
}