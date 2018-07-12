#include "InoSetting.cpp"
#include "CarMovementProxy.h"
#include "CarMovement.h"
#include "Controller.h"

#ifdef RUN_CAR_INO
#define setup_car() setup()
#define loop_car()  loop()
#endif

namespace controlling_car_ino {
	char command;

	const int pinLeftMotorGo = 9;     //좌측모터전진(IN2)
	const int pinLeftMotorBack = 8;     //좌측모터후진(IN1)
	const int pinRightMotorGo = 10;    // 우측모터전진(IN3)
	const int pinRightMotorBack = 11;    // 우측모터후진(IN4)
	int motorPins[4] = {pinLeftMotorGo, pinLeftMotorBack, pinRightMotorGo, pinRightMotorBack};

	// float car_width = 20;
	Car car = Car();
	CarMovement carMovement = static_cast<CarMovement>(CarMovementAnalog(motorPins, car));
	ControllerHandler controllerHandler = ControllerHandler(static_cast<CarMovementProxy>(carMovement));
	//	CarPropertyFinder carPropertyFinder(c,(CarMovement) CarMovementAnalog(5,6,7,8,c), Scaner(9,10,11));
}

void setup_controlling_car() {
	pinMode(controlling_car_ino::pinLeftMotorGo, OUTPUT);
	pinMode(controlling_car_ino::pinLeftMotorBack, OUTPUT);
	pinMode(controlling_car_ino::pinRightMotorGo, OUTPUT);
	pinMode(controlling_car_ino::pinRightMotorBack, OUTPUT);

	Serial.begin(9600);
}

void loop_controlling_car() {
	if (Serial.available() > 0) {
		controlling_car_ino::command = Serial.read();
		controlling_car_ino::controllerHandler.handleInput(controlling_car_ino::command);
	}

	// test_move();
}

namespace avoiding_car_ino {

}

void setup_avoiding_car_ino() {

}

void loop_avoiding_car_ino() {

}

typedef void (*loopFunction)();
loopFunction currentLoop;
const int pinCarMode = 12;

void setup_car() {
	pinMode(pinCarMode, INPUT);
	if (digitalRead(pinCarMode)) {
		setup_avoiding_car_ino();
		currentLoop = loop_avoiding_car_ino;
	} else {
		setup_controlling_car();
		currentLoop = loop_controlling_car;
	}
}

void loop_car(){
	currentLoop();
}



// void test_move() {
// 	myCar.goForward(255.0, 100.0);
// 	myCar.goBackward(255.0, 100.0);
// 	myCar.spinLeft(200.0, 0.0 , 360.0);
// 	myCar.turnRight(200.0, 10.0, 360.0);
// }


//#include "share.h"
//
//// Loop function callback (to speed things up)
//typedef void (*loopfunction)();
//loopfunction currentloop;
//
//const int RXTX_PIN = 8;
//
//void setup()
//{
//	pinMode(RXTX_PIN,INPUT);
//	if (digitalRead(RXTX_PIN))
//	{
//		setup_tx();
//		currentloop = loop_tx;
//	}
//	else
//	{
//		setup_rx();
//		currentloop = loop_rx;
//	}
//}
//
//void loop()
//{
//	currentloop();
//}
//
//void setup_tx(){}
//void loop_tx(){}
//
//void setup_rx(){}
//void loop_rx(){}