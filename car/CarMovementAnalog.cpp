//
// Created by Administrator on 2018-04-04.
//

#include "CarMovementAnalog.h"

void CarMovementAnalog::setMotorSpeed(float right_speed, float left_speed) {
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