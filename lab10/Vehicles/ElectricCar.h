#pragma once
#ifndef ELECTRIC_CAR_H
#define ELECTRIC_CAR_H
#include "Car.h"
#include "ElectricVehicle.h"

class ElectricCar : public ElectricVehicle, public Car
{
public:
	ElectricCar(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = ELECTRIC, int numberOfSeats = 0, int powerReserve = 0);
	~ElectricCar();
	virtual void engineOn() const override;
	virtual void engineOff() const override;
	virtual std::string toString() const override;
};

#endif // ELECTRIC_CAR_H