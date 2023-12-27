#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
#include <vector>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

enum EngineType
{
	PETROL = 0,
	DIESEL,
	GAS,
	ELECTRIC
};

std::string engineTypeToString(EngineType engineType);

class Vehicle
{
public:
	/// конструкторы должны быть даже в абстрактном, добавили конструктор дефолтный и параметризованный, упростили
	/// чтобы проще вызывать конструктор с меньшим числом параметром через конструктор с большим числом параметров
	Vehicle() : Vehicle(0, 0, PETROL) {
		spdlog::debug("Vehicle's costr with maxSpeed = {0:d}; engineCapacity = {1:f}", 0, 0.);
	};
	Vehicle(int maxSpeed) : Vehicle(maxSpeed, 0, PETROL) {
		spdlog::debug("Vehicle's costr with maxSpeed = {0:d}; engineCapacity = {1:f}", maxSpeed, 0.);
	};
	Vehicle(int maxSpeed, double engineCapacity) : Vehicle(maxSpeed, engineCapacity, PETROL) {
		spdlog::debug("Vehicle's costr with maxSpeed = {0:d}; engineCapacity = {1:f}", maxSpeed, engineCapacity);
	};
	Vehicle(int maxSpeed = 0, double engineCapacity = 0, EngineType engineType = PETROL) : maxSpeed_(maxSpeed), engineCapacity_(engineCapacity), engineType_(engineType) {
		spdlog::debug("Vehicle's costr with maxSpeed = {0:d}; engineCapacity = {1:f}; engineType = {2:s}", maxSpeed, engineCapacity, engineTypeToString(engineType));
	}
	~Vehicle();
	Vehicle(const Vehicle& other);
	Vehicle& operator= (const Vehicle& other);
	Vehicle(Vehicle&& moved) noexcept;
	Vehicle& operator= (Vehicle&& moved) noexcept;

	virtual void setMaxSpeed(const int& maxSpeed);
	virtual void setEngineCapacity(const double& engineCapacity);
	virtual void setEngineType(const EngineType& engineType);
	virtual std::string toString() const;
	virtual void engineOn() const = 0;
	virtual void engineOff() const = 0;

	int getMaxSpeed() const;
	double getEngineCapacity() const;
	std::string getEngineType() const;

protected:
	int maxSpeed_;
	double engineCapacity_;
	EngineType engineType_;
};

#endif // VEHICLE_H