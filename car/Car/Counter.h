//
// Created by Enjoeyland on 2018-05-03.
//

#ifndef COUNTER_H
#define COUNTER_H

#include "ObserverPattern.h"

class Counter : public Subject
{
public:
	int triggerInt;
public:
	explicit Counter(int triggerInt);
public:
	void increase();
protected:
	int counter;
	void checkConditon();
	void resetCounter();
};

#endif //COUNTER_H
