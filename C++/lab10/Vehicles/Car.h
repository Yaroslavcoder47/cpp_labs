#pragma once

#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"

class Car : virtual public Vehicle
{
public:
	Car(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = PETROL, int numberOfSeats_ = 0);
	virtual ~Car();
	virtual void engineOn() const override;
	virtual void engineOff() const override;
	virtual std::string toString() const override;
protected:
	int numberOfSeats_;
};

#endif //CAR_H

