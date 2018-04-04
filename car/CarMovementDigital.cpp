//
// Created by Enjoeyland on 2018-04-04.
//

#include "CarMovementDigital.h"

void CarMovementDigital::setMotorSpeed(float right_speed, float left_speed) {
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