//
// Created by Administrator on 2018-05-03.
//

#ifndef OBSERVERPATTERN_H
#define OBSERVERPATTERN_H

#include <vector>

class Subject;

class Observer
{
public:
	Subject *subject;

public:
	explicit Observer(Subject *subject);

public:
	void listen();

protected:
	virtual void update() = 0;
};

class Subject
{
	vector < class Observer * > observerVector;

public:
	void attach(Observer *obs);
	virtual void notify();
};

#endif //OBSERVERPATTERN_H
