//
// Created by Administrator on 2018-05-03.
//

#ifndef CAR_CONTROLLER_H
#define CAR_CONTROLLER_H

// todo : thread 없애기

//#include <mthread.h>
#include "ObserverPattern.h"
#include "Counter.h"

//#define OUTPUT_PIN 5
//#define NUM_SWITCHES 3

class ControllerHandler : public Observer
{
public:
	explicit ControllerHandler(Counter *counter);
	void inputHandle(char data);
};

//class PinInputHandler : public SwitchInput
//{
//public:
//	PinInputHandler(const Counter &counter, int pin, Type type = SwitchInput::pull_down);
//
//public:
//	void on_close() final;
//
//protected:
//	Counter counter;
//};

//SwitchInput::Type switchType[] = {
//		SwitchInput::pull_up_internal,
//		SwitchInput::pull_up,
//		SwitchInput::pull_down
//};

//int switch_pin[] = { 2, 3, 4 };

//void setup()
//{
//	pinMode(OUTPUT_PIN, OUTPUT);
//	digitalWrite(OUTPUT_PIN, LOW);
//	MySwitch *sw[NUM_SWITCHES];
//	int i;
//	for(i = 0; i < NUM_SWITCHES; i++)
//	{
//		sw[i] = new MySwitch(switch_pin[i], switch_type[i]);
//		main_thread_list->add_thread(sw[i]);
//	}
//}




#endif //CAR_CONTROLLER_H
