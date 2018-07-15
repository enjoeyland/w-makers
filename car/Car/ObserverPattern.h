
//
// Created by Administrator on 2018-05-03.
//

#ifndef OBSERVERPATTERN_H
#define OBSERVERPATTERN_H

#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <set>

class Subject;

class Observer
{
public:
	Subject *subject;

public:
	explicit Observer(Subject *subject);

public:
	void listen();
	virtual void update() = 0;
};

class Subject
{
public:
	std::set < class Observer * > observerSet;

	void attach(Observer * observer);
	void detach(Observer * observer);
	virtual void notify();
};

#endif //OBSERVERPATTERN_H
