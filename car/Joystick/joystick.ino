#include <Arduino.h>
#include "CarMovementSerialPrint.h"
#include "Controller.h"


int pinUp = 8;
int pinLeft = 11;
int pinDown = 10;
int pinRight = 9;

CarMovementSerialPrint carMovementSerialPrint = CarMovementSerialPrint();
ControllerHandler controllerHandler = ControllerHandler(carMovementSerialPrint);

//void setPIn() {
//	pinMode(pinUp,INPUT);
//	pinMode(pinLeft,INPUT);
//	pinMode(pinDown,INPUT);
//	pinMode(pinRight,INPUT);
//}

void setup() {
	pinMode(pinUp,INPUT);
	pinMode(pinLeft,INPUT);
	pinMode(pinDown,INPUT);
	pinMode(pinRight,INPUT);
//	setPin();
	Serial.begin(9600);
}

void loop() {
	int upPinData = digitalRead(pinUp);
	int downPinData = digitalRead(pinDown);
	int leftPinData = digitalRead(pinLeft);
	int rightPinData = digitalRead(pinRight);
	int pinData[] = {upPinData, downPinData, leftPinData, rightPinData};
	controllerHandler.handleInput(controllerHandler.handleInputPin(pinData));

//	Serial.print(upPinData);
//	Serial.print(",");
//	Serial.print(downPinData);
//	Serial.print(",");
//	Serial.print(leftPinData);
//	Serial.print(",");
//	Serial.println(rightPinData);

	delay(200);
}