#include "ElectricVehicle.h"

ElectricVehicle::ElectricVehicle(int maxSpeed, double engineCapacity, EngineType engineType, int powerReserve) : Vehicle(maxSpeed, ELECTRIC, engineType), powerReserve_(powerReserve)
{
	spdlog::debug("ElectricVehicle costr with parametres: {0:d}, {1:f}, {2:s}, {3:d}", maxSpeed, engineCapacity, engineTypeToString(ELECTRIC), powerReserve);
}

std::string ElectricVehicle::toString() const{
	spdlog::info("ElectricVehicle's toString function");
	return Vehicle::toString() + " Power reserve: " + std::to_string(powerReserve_) + "km";
}

ElectricVehicle::~ElectricVehicle() {
	spdlog::debug("ElectricVehicle's destr");
}

void ElectricVehicle::engineOn() const {
	spdlog::info("ElectricVehicle engine is on");
}

void ElectricVehicle::engineOff() const{
	spdlog::info("ElectricVehicle engine is off");
}
