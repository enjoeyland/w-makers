#include "CarMovement.h"

// f,b,tl 수정 완료
// speed값을 0~255에 맞도록 수정 해야 될거 같다.

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

inline float CarMovement::getAngularSpeed(float &average_speed, float &radius){
	return 2 * average_speed / (2 * radius + car_width); // 각속도
}

//inline float getRadian(float degree){
//	return degree * PI / 180;
//}

inline void turnSpecificDegree(const float &angular_speed, const float &degree) {
	float angle_radian = degree * PI / 180;
	float delay_time = angle_radian / angular_speed;

	delay(delay_time * 1000);
}


// 앞으로, 뒤로
void CarMovement::goForward	(const float &speed){
	setMotorSpeed(speed, speed);
}

void CarMovement::goBackward	(const float &speed) {
	setMotorSpeed(-speed, -speed);
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