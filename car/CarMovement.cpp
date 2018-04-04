#include "CarMovement.h"

// f,b,tl 수정 완료
// speed값을 0~255에 맞도록 수정 해야 될거 같다.

CarMovement::CarMovement(
	int pin_right_motor_go,
	int pin_right_motor_back,
	int pin_left_motor_go,
	int pin_left_motor_back,
	float car_width) :
		pin_right_motor_go(pin_right_motor_go),
		pin_right_motor_back(pin_right_motor_back),
		pin_left_motor_go(pin_left_motor_go),
		pin_left_motor_back(pin_left_motor_back),
		car_width(car_width) {}

inline float CarMovement::getAngularSpeed(float average_speed, float radius){
	return 2 * average_speed / (2 * radius + car_width); // 각속도
}

inline float getRadian(float degree){
	return degree * PI / 180;
}

void CarMovement::goForward	(float speed){
	setMotorSpeed(speed, speed);
}

void CarMovement::goBackward	(float speed) {
	setMotorSpeed(-speed, -speed);
}

void CarMovement::stop (void) {
	setMotorSpeed(0, 0);
}


// 회전
// '라디안'이 아니라 '도'로
void CarMovement::turnLeft	(float average_speed, float radius) {
	float angular_speed = getAngularSpeed(average_speed, radius);

	float right_speed = angular_speed * (radius + car_width);
	float left_speed = angular_speed * radius;

	setMotorSpeed(right_speed, left_speed);
}

void CarMovement::turnLeft	(float average_speed, float radius, float degree) {
	float angular_speed = getAngularSpeed(average_speed, radius);
	float angle_radian = getRadian(degree);
	float delay_time = angle_radian / angular_speed;

	float right_speed = angular_speed * (radius + car_width);
	float left_speed = angular_speed * radius;

	setMotorSpeed(right_speed, left_speed);

	delay(delay_time * 1000);  //딜레이
}

void CarMovement::turnRight	(float average_speed, float radius) {
	analogWrite(pin_right_motor_go,0); 
	analogWrite(pin_right_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
	
	analogWrite(pin_left_motor_go,200); 
	analogWrite(pin_left_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
}

void CarMovement::turnRight	(float average_speed, float radius, float angle) {
	analogWrite(pin_right_motor_go,0); 
	analogWrite(pin_right_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
	
	analogWrite(pin_left_motor_go,200); 
	analogWrite(pin_left_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
	delay(time * 1000);  //딜레이  
}


// 제자리리에서 회전
void CarMovement::spinLeft	(float average_speed, float radius) {
	analogWrite(pin_right_motor_go,200); 
	analogWrite(pin_right_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.

	analogWrite(pin_left_motor_go,0); 
	analogWrite(pin_left_motor_back,200);//PWM값 0~255 조정,모터의 회전속도 조절.
}

void CarMovement::spinLeft	(float average_speed, float radius, float angle) {
	analogWrite(pin_right_motor_go,200); 
	analogWrite(pin_right_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.

	analogWrite(pin_left_motor_go,0); 
	analogWrite(pin_left_motor_back,200);//PWM값 0~255 조정,모터의 회전속도 조절.
	delay(time * 1000);  //딜레이 
}


void CarMovement::spinRight	(float average_speed, float radius) {
	analogWrite(pin_right_motor_go,0); 
	analogWrite(pin_right_motor_back,200);//PWM값 0~255 조정,모터의 회전속도 조절.

	analogWrite(pin_left_motor_go,200); 
	analogWrite(pin_left_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
}

void CarMovement::spinRight	(float average_speed, float radius, float angle) {
	analogWrite(pin_right_motor_go,0); 
	analogWrite(pin_right_motor_back,200);//PWM값 0~255 조정,모터의 회전속도 조절.

	analogWrite(pin_left_motor_go,200); 
	analogWrite(pin_left_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
	delay(time * 1000);  //딜레이 
}