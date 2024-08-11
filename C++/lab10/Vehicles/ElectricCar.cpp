#include "ElectricCar.h"

ElectricCar::ElectricCar(int maxSpeed, double engineCapacity, EngineType engineType, int numberOfSeats, int powerReserve) : Vehicle(maxSpeed, engineCapacity, ELECTRIC),
	ElectricVehicle(maxSpeed, engineCapacity, ELECTRIC, powerReserve),
	Car(maxSpeed, engineCapacity, ELECTRIC, numberOfSeats)
{
	spdlog::debug("ElectricCar costr with parametres: {0:d}, {1:f}, {2:s}, {3:d}, {4:d}", maxSpeed, engineCapacity, engineTypeToString(ELECTRIC), numberOfSeats, powerReserve);
}

std::string ElectricCar::toString() const {
	spdlog::info("ElectricCar's toString function");
	return Vehicle::toString() + " Power reserve: " + std::to_string(powerReserve_) + "km";
}

ElectricCar::~ElectricCar() {
	spdlog::debug("ElectricCar's destr");
}

void ElectricCar::engineOn() const {
	spdlog::info("ElectricCar engine is on");
}

void ElectricCar::engineOff() const {
	spdlog::info("ElectricCar engine is off");
}
