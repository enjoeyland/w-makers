//
// Created by Administrator on 2018-05-03.
//

#include "ObserverPattern.h"

// Observer
Observer::Observer(Subject *subject) : subject(subject){
	listen();
}

void Observer::listen() {
	subject->attach(this);
}


// Subject
void Subject::attach(Observer * observer) {
	observerSet.insert(observer);

}

void Subject::detach(Observer * observer) {
	observerSet.erase(observer);
}

void Subject::notify() {
//	for(std::set::iterator IterPos = observerSet.begin(); IterPos != observerSet.end(); ++IterPos ) {} <- 잘안됨
	for(auto IterPos : observerSet){
		IterPos->update();
	}
}



