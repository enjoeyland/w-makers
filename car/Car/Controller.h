//
// Created by Administrator on 2018-05-03.
//

#ifndef CAR_CONTROLLER_H
#define CAR_CONTROLLER_H

#include "CarMovementProxy.h"

class HandlerProxy
{
public:
	virtual void handleInput(char data){}; // CF : type 확장성을 위해 template 으로 바꿔도 됨
};

class ControllerHandler : public HandlerProxy
{
public:
	explicit ControllerHandler(CarMovementProxy * carMovement): carMovement(carMovement){};
	~ControllerHandler(){delete carMovement;};
protected:
	CarMovementProxy * carMovement;

public:
	char handleInputPin(int *pinData);
	void handleInput(char data) override;
};

#endif //CAR_CONTROLLER_H
