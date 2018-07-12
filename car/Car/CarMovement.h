#ifndef CAR_CARMOVEMENT_H
#define CAR_CARMOVEMENT_H

// todo : proxy 패턴을 쓸 수 있게 개선하기

//namespace carMovement {

#include "Car.h"
#include "ObserverPattern.h"
#include "CarMovementProxy.h"
#include <Arduino.h>

#define CAR_STOP    0
#define GO_FORWARD  1
#define GO_BACKWARD 2
#define TURN_LEFT   3
#define TURN_RIGHT  4
#define SPIN_LEFT   5
#define SPIN_RIGHT  6

//class CarMovement : public CarMovementProxy
//{
//public:
//	// 앞으로, 뒤로
//	void goForward(double speed, double distance) override;
//	void goBackward(double speed, double distance) override;
//	void stop() override;
//
//	// 회전
//	// 라디안이 아니라 도로
//	void turnLeft(double average_speed, double radius, double degree) override;
//	void turnRight(double average_speed, double radius, double degree) override;
//
//	// 제자리리에서 회전
//	void spinLeft(double average_speed, double radius, double degree) override;
//	void spinRight(double average_speed, double radius, double degree) override;
//
//};


class CarMovement : public CarMovementProxy
{
	// control of DC motor
public:
	struct CarMovementError {
		int moveType;
		int leftHexSpeed;
		int rightHexSpeed;
		double leftSpeedDiff;
		double rightSpeedDiff;

	} currentMovingError;

protected:
	// pin of L293D diver
	int pin_LeftMotor_go;
	int pin_leftMotor_back;
	int pin_rightMotor_go;
	int pin_rightMotor_back;

	Car car;

	// const double PI = 3.14; // Arudino.h has PI value

public:
	// \param *dcMotorPins - {int pin_leftMotor_go,
	//			int pin_leftMotor_back,
	//			int pin_rightMotor_go,
	//			int pin_rightMotor_back}
	CarMovement(int *dcMotorPins, Car car);

public:
	// 앞으로, 뒤로
	void goForward(double speed, double distance) override;
	void goBackward(double speed, double distance) override;
	void stop() override;

	// 회전
	// 라디안이 아니라 도로
	void turnLeft(double average_speed, double radius, double degree) override;
	void turnRight(double average_speed, double radius, double degree) override;

	// 제자리리에서 회전
	void spinLeft(double average_speed, double radius = 0, double degree) override;
	void spinRight(double average_speed, double radius = 0, double degree) override;

protected:
	virtual void setMotorSpeed(int rightHexSpeed, int leftHexSpeed){};

	inline double getRpsSpeed(double hexSpeed){
		return hexSpeed * car.rps;
	}

	inline double getHexSpeed(double rpsSpeed) {
		return  rpsSpeed / car.rps;
	}

	inline double getAngularSpeed(double averageSpeed, double radius){
		return 2 * averageSpeed / (2 * radius + car.width); // 각속도
	}

	inline void turnSpecificDegree(double angularSpeed, double degree){
		double angleRadian = degree * PI / 180;
		double delayTime = angleRadian / angularSpeed;

		delay(static_cast<unsigned long>(delayTime * 1000));
		stop();
	}


};

class CarMovementAnalog : public CarMovement {
public:
	// \param *dcMotorPins - {int pin_leftMotor_go,
	//			int pin_leftMotor_back,
	//			int pin_rightMotor_go,
	//			int pin_rightMotor_back}
	CarMovementAnalog(int *dcMotorPins, Car car):
	CarMovement(dcMotorPins, car) {};

public:
	void setMotorSpeed(int rightHexSpeed, int leftHexSpeed) override;

};

class CarMovementDigital : public CarMovement {
public:
	CarMovementDigital(int *dcMotorPins, Car car):
	CarMovement(dcMotorPins, car) {};
public:
	void setMotorSpeed(int rightHexSpeed, int leftSpeed) override;
};
//}
#endif //CAR_CARMOVEMENT_H
