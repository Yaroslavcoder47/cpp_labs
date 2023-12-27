#pragma once
#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H
#include "Vehicle.h"

class ElectricVehicle : virtual public Vehicle
{
public:
	ElectricVehicle(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = ELECTRIC, int powerReserve = 0);
	~ElectricVehicle();
	virtual void engineOn() const override;
	virtual void engineOff() const override;
	virtual std::string toString() const override;
protected:
	int powerReserve_;
};


#endif // ELECTRICVEHICLE_H