//
// Created by Enjoeyland on 2018-05-03.
//

#include "Controller.h"



char ControllerHandler::handleInputPin(int *pinData) {
	int pinUpData = pinData[0];
	int pinDownData = pinData[1];
	int pinLeftData = pinData[2];
	int pinRightData = pinData[3];

	if (pinUpData == 1){
		if (pinLeftData == 0 && pinRightData == 0) {
			return 'F';
		} else if (pinLeftData == 1&& pinRightData == 0) {
			return 'G';
		} else if (pinLeftData == 0 && pinRightData == 1){
			return 'I';
		}
	} else{
		if (pinDownData == 1){
			if (pinLeftData == 0 && pinRightData == 0) {
				return 'B';
			} else if (pinLeftData == 1&& pinRightData == 0) {
				return 'H';
			} else if (pinLeftData == 0 && pinRightData == 1){
				return 'J';
			}
		} else {
			if (pinLeftData == 0 && pinRightData == 0) {
				return 'S';
			} else if (pinLeftData == 1&& pinRightData == 0) {
				return 'L';
			} else if (pinLeftData == 0 && pinRightData == 1){
				return 'R';
			}
		}
	};
}

void ControllerHandler::handleInput(char data) {
	switch(data) {
		case 'F':
			carMovement.goForward(255, 0);
			break;
		case 'B':
			carMovement.goBackward(255, 0);
			break;
		case 'L':
			carMovement.spinLeft(255,0,0);
			break;
		case 'R':
			carMovement.spinRight(255,0,0);
			break;
		case 'G':
			carMovement.turnLeft(255,10,0);
			break;
		case 'I':
			carMovement.turnRight(255,10,0);
			break;
		case 'H':
			carMovement.turnLeft(-255,10,0);
			break;
		case 'J':
			carMovement.turnRight(-255,10,0);
			break;
		case 'S':
			carMovement.stop();
			break;

		case 'U':
			// back Lights On
			break;
		case 'u':
			// back light off
			break;
		case 'V':
			// Horn on
			break;
		case 'v':
			// Horn off
			break;
		case 'X':
			// Extra On
			break;
		case 'x':
			// Extra On
			break;


//		case '0':
//			setSpeed(0);
//			break;
//		case '1':
//			setSpeed(10);
//			break;
//		case '2':
//			setSpeed(20);
//			break;
//		case '3':
//			setSpeed(30);
//			break;
//		case '4':
//			setSpeed(40);
//			break;
//		case '5':
//			setSpeed(50);
//			break;
//		case '6':
//			setSpeed(60);
//			break;
//		case '7':
//			setSpeed(70);
//			break;
//		case '8':
//			setSpeed(80);
//			break;
//		case '9':
//			setSpeed(90);
//			break;
//		case 'q':
//			setSpeed(100);
//			break;
//
//
//		case 'D':
////			stop all
//			stop;
//			break;

		default:break;
	}

}

// defining PinInputHandler
//PinInputHandler::PinInputHandler(const Counter &counter, int pin, SwitchInput::Type type) :
//		counter(counter), SwitchInput(pin, DEFAULT_DEBOUNCE, type) {}
//
//void PinInputHandler::on_close()
//{
//	counter.increase();
//}