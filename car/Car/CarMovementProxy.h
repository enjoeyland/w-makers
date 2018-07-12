//
// Created by Administrator on 2018-07-12.
//

#ifndef CAR_CARMOVEMENTPROXY_H
#define CAR_CARMOVEMENTPROXY_H

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

#endif //CAR_CARMOVEMENTPROXY_H
