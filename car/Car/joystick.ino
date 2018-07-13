#ifndef JOYSTICK_INO
#define JOYSTICK_INO

//#include "car.ino"
#include "CompileInoSetting.cpp"
#include <Arduino.h>
#include "CarMovementSerialPrint.h"
#include "Controller.h"

#ifdef COMPILE_JOYSTICK_INO
#define setup_joystick() setup()
#define loop_joystick() loop()
#endif //COMPILE_JOYSTICK_INO

namespace joystick_ino {

	int pinUp = 8;
	int pinLeft = 11;
	int pinDown = 10;
	int pinRight = 9;

	CarMovementSerialPrint carMovementSerialPrint;
	ControllerHandler controllerHandler = ControllerHandler(&carMovementSerialPrint);
}

//void setPIn() {
//	pinMode(pinUp,INPUT);
//	pinMode(pinLeft,INPUT);
//	pinMode(pinDown,INPUT);
//	pinMode(pinRight,INPUT);
//}

void setup_joystick() {
	pinMode(joystick_ino::pinUp, INPUT);
	pinMode(joystick_ino::pinLeft, INPUT);
	pinMode(joystick_ino::pinDown, INPUT);
	pinMode(joystick_ino::pinRight, INPUT);
//	setPin();
	Serial.begin(9600);
}

void loop_joystick() {
	int upPinData = digitalRead(joystick_ino::pinUp);
	int downPinData = digitalRead(joystick_ino::pinDown);
	int leftPinData = digitalRead(joystick_ino::pinLeft);
	int rightPinData = digitalRead(joystick_ino::pinRight);
	int pinData[] = {upPinData, downPinData, leftPinData, rightPinData};
	joystick_ino::controllerHandler.handleInput(joystick_ino::controllerHandler.handleInputPin(pinData));

//	Serial.print(upPinData);
//	Serial.print(",");
//	Serial.print(downPinData);
//	Serial.print(",");
//	Serial.print(leftPinData);
//	Serial.print(",");
//	Serial.println(rightPinData);

	delay(100);
}

#endif //JOYSTICK_INO