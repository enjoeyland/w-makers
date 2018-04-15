#include "CarMovement.h"
using namespace carMovement;
#include "CoordinateSystem.h"
using namespace coordinateSystem;

int pinLeftMotorGo = 9;     //좌측모터전진(IN2)
int pinLeftMotorBack = 8;     //좌측모터후진(IN1)

int pinRightMotorGo = 10;    // 우측모터전진(IN3)
int pinRightMotorBack = 11;    // 우측모터후진(IN4)

float car_width = 20;

CarMovement *myCar = new CarMovementAnalog(pinLeftMotorGo, pinLeftMotorBack, pinRightMotorGo, pinRightMotorBack, car_width);


void setup()
{
}

void loop()
{
	test_move();
}

void test_move() {
	myCar->goForward(255.f, 100.f);
	myCar->goBackward(255.f, 100.f);
	myCar->spinLeft(200.f, 0.f , 360.f);
	myCar->turnRight(200.f, 10.f, 360.f);
}