#ifndef CAR_CARMOVEMENT_H
#define CAR_CARMOVEMENT_H


class CarMovement {
protected:
	int pin_left_motor_go;
	int pin_left_motor_back;

	int pin_right_motor_go;
	int pin_right_motor_back;

	float car_width;

	const float PI = 3.14;

public:
	CarMovement(
		int pin_right_motor_go,
		int pin_right_motor_back,
		int pin_left_motor_go,
		int pin_left_motor_back,
		float car_width);
	~CarMovement();

public:
	// 앞으로, 뒤로
	void goForward	(float speed);
	void goBackward	(float speed);
	void stop ();

	// 회전
	// 라디안이 아니라 도로
	void turnLeft	(float average_speed, float radius);
	void turnLeft	(float average_speed, float radius, float degree);
	void turnRight	(float average_speed, float radius);
	void turnRight	(float average_speed, float radius, float degree);

	// 제자리리에서 회전
	void spinLeft	(float average_speed, float radius);
	void spinLeft	(float average_speed, float radius, float degree);
	void spinRight	(float average_speed, float radius);
	void spinRight	(float average_speed, float radius, float degree);

protected:
	virtual void setMotorSpeed(float right_speed, float left_speed) = 0;
	inline float getAngularSpeed(float average_speed, float radius);
	inline float getRadian(float degree);

};

#endif //CAR_CARMOVEMENT_H