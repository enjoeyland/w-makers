
//#include "CarPropertyFinder.h"
#include "CarMovementProxy.h"
#include "CarMovement.h"
#include "Controller.h"

char command;

int pinLeftMotorGo = 9;     //좌측모터전진(IN2)
int pinLeftMotorBack = 8;     //좌측모터후진(IN1)

int pinRightMotorGo = 10;    // 우측모터전진(IN3)
int pinRightMotorBack = 11;    // 우측모터후진(IN4)
int motorPins[4] = {pinLeftMotorGo, pinLeftMotorBack, pinRightMotorGo, pinRightMotorBack};

// float car_width = 20;
Car car = Car();
CarMovement carMovement = static_cast<CarMovement>(CarMovementAnalog(motorPins, car));
ControllerHandler controllerHandler = ControllerHandler(static_cast<CarMovementProxy>(carMovement));
//	CarPropertyFinder carPropertyFinder(c,(CarMovement) CarMovementAnalog(5,6,7,8,c), Scaner(9,10,11));

void setup()
{
	pinMode(pinLeftMotorGo, OUTPUT);
	pinMode(pinLeftMotorBack, OUTPUT);
	pinMode(pinRightMotorGo, OUTPUT);
	pinMode(pinRightMotorBack, OUTPUT);

	Serial.begin(9600);
}

void loop()
{
	if(Serial.available() > 0){
		command = Serial.read();
		controllerHandler.handleInput(command);
	}

	// test_move();
}

// void test_move() {
// 	myCar.goForward(255.0, 100.0);
// 	myCar.goBackward(255.0, 100.0);
// 	myCar.spinLeft(200.0, 0.0 , 360.0);
// 	myCar.turnRight(200.0, 10.0, 360.0);
// }