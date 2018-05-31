//
// Created by Enjoeyland on 2018-05-03.
//

#include "Controller.h"

ControllerHandler::ControllerHandler(Counter *counter) : Observer(counter){

}

void ControllerHandler::inputHandle(char data) {
	switch(data) {
		case data == 'F':
			forward;
			break;
		case data == 'B':
			backward;
			break;
		case data == 'L':
			spinLeft;
			break;
		case data == 'R':
			spinRight;
			break;
		case data == 'G':
			turnLeft;
			break;
		case data == 'I':
			turnRight;
			break;
		case data == 'H':
			turnLeft;
			break;
		case data == 'J':
			turnRight;
			break;
		case data == 'S':
			stop;
			break;
		case data == 'U':
			// back Lights On
			break;
		case data == 'u':
			// back light off
			break;
		case data == 'V':
			// Horn on
			break;
		case data == 'v':
			// Horn off
			break;
		case data == 'X':
			// Extra On
			break;
		case data == 'x':
			// Extra On
			break;
		case data == '0':
			setSpeed(0);
			break;
		case data == '1':
			setSpeed(10);
			break;
		case data == '2':
			setSpeed(20);
			break;
		case data == '3':
			setSpeed(30);
			break;
		case data == '4':
			setSpeed(40);
			break;
		case data == '5':
			setSpeed(50);
			break;
		case data == '6':
			setSpeed(60);
			break;
		case data == '7':
			setSpeed(70);
			break;
		case data == '8':
			setSpeed(80);
			break;
		case data == '9':
			setSpeed(90);
			break;
		case data == 'q':
			setSpeed(100);
			break;
		case data == 'D':
			//stop all
			stop;
			break;

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