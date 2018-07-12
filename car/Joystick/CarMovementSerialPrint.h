#ifndef CAR_CARMOVEMENTSERIALPRINT_H
#define CAR_CARMOVEMENTSERIALPRINT_H

// todo : proxy 패턴을 쓸 수 있게 개선하기

//namespace carMovement {


#include <Arduino.h>


#define CAR_STOP    0
#define GO_FORWARD  1
#define GO_BACKWARD 2
#define TURN_LEFT   3
#define TURN_RIGHT  4
#define SPIN_LEFT   5
#define SPIN_RIGHT  6

class CarMovementProxy
{
	// proxy of CarMovement for other use(joystick call)
public:
	// 앞으로, 뒤로
	virtual void goForward(double speed, double distance){};
	virtual void goBackward(double speed, double distance){};
	virtual void stop(){};

	// 회전
	// 라디안이 아니라 도로
	virtual void turnLeft(double average_speed, double radius, double degree){};
	virtual void turnRight(double average_speed, double radius, double degree){};

	// 제자리리에서 회전
	virtual void spinLeft(double average_speed, double radius, double degree){};
	virtual void spinRight(double average_speed, double radius, double degree){};

};

class CarMovementSerialPrint : public CarMovementProxy
{
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
	void spinLeft(double average_speed, double radius, double degree) override;
	void spinRight(double average_speed, double radius, double degree) override;

};

//}
#endif //CAR_CARMOVEMENT_H
