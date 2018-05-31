//
// Created by Administrator on 2018-05-03.
//

#include "Counter.h"

Counter::Counter(int triggerInt) : triggerInt(triggerInt) {}

void Counter::increase() {
	counter++;
}

void Counter::checkConditon() {
	if (counter == triggerInt) {
		resetCounter();
		notify();
	}
}

void Counter::resetCounter() {
	counter = 0;
}
