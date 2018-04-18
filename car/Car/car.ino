#include "CarMovement.h"
//using namespace carMovement;
#include "CoordinateSystem.h"
using namespace coordinateSystem;

int pinLeftMotorGo = 9;     //좌측모터전진(IN2)
int pinLeftMotorBack = 8;     //좌측모터후진(IN1)

int pinRightMotorGo = 10;    // 우측모터전진(IN3)
int pinRightMotorBack = 11;    // 우측모터후진(IN4)

float car_width = 20;

CarMovement myCar = static_cast<CarMovement> (CarMovementAnalog(pinLeftMotorGo, pinLeftMotorBack, pinRightMotorGo, pinRightMotorBack, car_width));


void setup()
{
}

void loop()
{
	test_move();
}

void test_move() {
	myCar.goForward(255.0, 100.0);
	myCar.goBackward(255.0, 100.0);
	myCar.spinLeft(200.0, 0.0 , 360.0);
	myCar.turnRight(200.0, 10.0, 360.0);
}