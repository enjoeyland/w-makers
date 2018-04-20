#ifndef CAR_CARMOVEMENT_H
#define CAR_CARMOVEMENT_H

//namespace carMovement {

class CarMovement {
	// control of DC motor

protected:
	// pin of L293D diver
	int pin_left_motor_go;
	int pin_left_motor_back;
	int pin_right_motor_go;
	int pin_right_motor_back;

	double car_width;

	const double PI = 3.14;

public:
	CarMovement(
			int pin_left_motor_go,
			int pin_left_motor_back,
			int pin_right_motor_go,
			int pin_right_motor_back,
			double car_width);

	~CarMovement();

public:
	// 앞으로, 뒤로
	void goForward(const double &speed, double distance = 0);

	void goBackward(const double &speed, double distance = 0);

	void stop();

	// 회전
	// 라디안이 아니라 도로
	void turnLeft(const double &average_speed, const double &radius, const double &degree = 0);

	void turnRight(const double &average_speed, const double &radius, const double &degree = 0);

	// 제자리리에서 회전
	void spinLeft(const double &average_speed, const double &radius, const double &degree = 0);

	void spinRight(const double &average_speed, const double &radius, const double &degree = 0);

protected:
	virtual void setMotorSpeed(const double &right_speed, const double &left_speed) = 0;

	inline double getAngularSpeed(const double &average_speed, const double &radius);

//	inline double getRadian(const double &degree);
	inline void turnSpecificDegree(const double &angular_speed, const double &degree);

};

class CarMovementAnalog : public CarMovement {
public:
	CarMovementAnalog(int pin_left_motor_go,
			int pin_left_motor_back,
			int pin_right_motor_go,
			int pin_right_motor_back,
			double car_width):
	CarMovement(pin_left_motor_go, pin_left_motor_back, pin_right_motor_go, pin_right_motor_back, car_width) {};
	~CarMovementAnalog();
public:
	virtual void setMotorSpeed(const double &right_speed, const double &left_speed);

};

class CarMovementDigital : public CarMovement {
public:
	CarMovementDigital(int pin_left_motor_go,
			int pin_left_motor_back,
			int pin_right_motor_go,
			int pin_right_motor_back,
			double car_width):
	CarMovement(pin_left_motor_go, pin_left_motor_back, pin_right_motor_go, pin_right_motor_back, car_width) {};
	~CarMovementDigital();
public:
	virtual void setMotorSpeed(const double &right_speed, const double &left_speed);
};
//}
#endif //CAR_CARMOVEMENT_H