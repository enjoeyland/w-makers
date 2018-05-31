//
// Created by Administrator on 2018-05-03.
//

#include "ObserverPattern.h"

Observer::Observer(Subject *subject) : subject(subject){
	listen();
}

void Observer::listen() {
	subject->attach(this);
}

void Subject::attach(Observer *obs) {
	observerVector.push_back(obs);
}

void Subject::notify() {
	for (int i = 0; i < observerVector.size(); i++)
		observerVector[i]->update();
}



