#ifndef CAR_CARMOVEMENTSERIALPRINT_H
#define CAR_CARMOVEMENTSERIALPRINT_H


#include "CarMovementProxy.h"
#include <Arduino.h>

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
