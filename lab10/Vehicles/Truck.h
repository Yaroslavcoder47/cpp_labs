#pragma once
#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : virtual public Vehicle
{
public:
	Truck(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = PETROL, int liftingCapacity = 0);
	~Truck();
	virtual void engineOn() const override;
	virtual void engineOff() const override;
	virtual std::string toString() const override;
protected:
	int liftingCapacity_;
};

#endif // TRUCK_H

