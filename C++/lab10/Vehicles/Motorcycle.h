#pragma once
#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : virtual public Vehicle
{
public:
	Motorcycle(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = PETROL, std::string country = "");
	~Motorcycle();
	virtual void engineOn() const override;
	virtual void engineOff() const override;
	virtual std::string toString() const override;
protected:
	std::string country_;
};

#endif // MOTORCYCLE_H