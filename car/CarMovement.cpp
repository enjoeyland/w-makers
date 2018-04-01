#include "CarMovement.h"

// f,b,tl 수정 완료
// speed값을 0~255에 맞도록 수정 해야 될거 같다.

CarMovement::CarMovement(
		int _pin_right_motor_go,
		int _pin_right_motor_back,
		int _pin_left_motor_go,
		int _pin_left_motor_back,
		float _car_width) {

	pin_right_motor_go = _pin_right_motor_go;
	pin_right_motor_back = _pin_right_motor_back;

	pin_left_motor_go = _pin_left_motor_go;
	pin_left_motor_back = _pin_left_motor_back;

	car_width = _car_width;
}

void CarMovement::goForward	(float _speed){
	analogWrite(pin_right_motor_go, _speed);//PWM값 0~255 조정,모터의 회전속도 조절.
	analogWrite(pin_right_motor_back, 0);

	analogWrite(pin_left_motor_go, _speed);//PWM값 0~255 조정,모터의 회전속도 조절.
	analogWrite(pin_left_motor_back, 0);
}

void CarMovement::goBackward	(float _speed) {
	analogWrite(pin_right_motor_go, 0);
	analogWrite(pin_right_motor_back, _speed);//PWM값 0~255 조정,모터의 회전속도 조절.

	analogWrite(pin_left_motor_go, 0);
	analogWrite(pin_left_motor_back, _speed);//PWM값 0~255 조정,모터의 회전속도 조절.
}

void CarMovement::stop (void) {
	digitalWrite(pin_right_motor_go, LOW);
	digitalWrite(pin_right_motor_back, LOW);
	
	digitalWrite(pin_left_motor_go, LOW);
	digitalWrite(pin_left_motor_back, LOW);
}


// 회전
// '라디안'이 아니라 '도'로
void CarMovement::turnLeft	(float _average_speed, float _radius) {
	float _angular_speed = 2 * _average_speed / (2 * _radius + car_width); // 각속도
	
	float _right_speed = _angular_speed * (_radius + car_width);
	float _left_speed = _angular_speed * _radius;

	analogWrite(pin_right_motor_go, _right_speed); 
	analogWrite(pin_right_motor_back, 0);//PWM값 0~255 조정,모터의 회전속도 조절.

	analogWrite(pin_left_motor_go, _left_speed); 
	analogWrite(pin_left_motor_back, 0);//PWM값 0~255 조정,모터의 회전속도 조절.
}

void CarMovement::turnLeft	(float _average_speed, float _radius, float _angle) {
	float _angular_speed = 2 * _average_speed / (2 * _radius + car_width); // 각속도
	float _angle_radian = _angle * pi / 180;
	float _delay_time = _angle_radian / _angular_speed;

	float _right_speed = _angular_speed * (_radius + car_width);
	float _left_speed = _angular_speed * _radius;

	analogWrite(pin_right_motor_go, _right_speed); 
	analogWrite(pin_right_motor_back, 0);//PWM값 0~255 조정,모터의 회전속도 조절.

	analogWrite(pin_left_motor_go, _left_speed); 
	analogWrite(pin_left_motor_back, 0);//PWM값 0~255 조정,모터의 회전속도 조절.

	delay(_angle_radian * 1000);  //딜레이 
}

void CarMovement::turnRight	(float _average_speed, float _radius) {
	analogWrite(pin_right_motor_go,0); 
	analogWrite(pin_right_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
	
	analogWrite(pin_left_motor_go,200); 
	analogWrite(pin_left_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
}

void CarMovement::turnRight	(float _average_speed, float _radius, float _angle) {
	analogWrite(pin_right_motor_go,0); 
	analogWrite(pin_right_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
	
	analogWrite(pin_left_motor_go,200); 
	analogWrite(pin_left_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
	delay(time * 1000);  //딜레이  
}


// 제자리리에서 회전
void CarMovement::spinLeft	(float _average_speed, float _radius) {
	analogWrite(pin_right_motor_go,200); 
	analogWrite(pin_right_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.

	analogWrite(pin_left_motor_go,0); 
	analogWrite(pin_left_motor_back,200);//PWM값 0~255 조정,모터의 회전속도 조절.
}

void CarMovement::spinLeft	(float _average_speed, float _radius, float _angle) {
	analogWrite(pin_right_motor_go,200); 
	analogWrite(pin_right_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.

	analogWrite(pin_left_motor_go,0); 
	analogWrite(pin_left_motor_back,200);//PWM값 0~255 조정,모터의 회전속도 조절.
	delay(time * 1000);  //딜레이 
}


void CarMovement::spinRight	(float _average_speed, float _radius) {
	analogWrite(pin_right_motor_go,0); 
	analogWrite(pin_right_motor_back,200);//PWM값 0~255 조정,모터의 회전속도 조절.

	analogWrite(pin_left_motor_go,200); 
	analogWrite(pin_left_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
}

void CarMovement::spinRight	(float _average_speed, float _radius, float _angle) {
	analogWrite(pin_right_motor_go,0); 
	analogWrite(pin_right_motor_back,200);//PWM값 0~255 조정,모터의 회전속도 조절.

	analogWrite(pin_left_motor_go,200); 
	analogWrite(pin_left_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
	delay(time * 1000);  //딜레이 
}