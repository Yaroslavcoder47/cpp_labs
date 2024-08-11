#include "Truck.h"

Truck::Truck(int maxSpeed, double engineCapacity, EngineType engineType, int liftingCapacity) : Vehicle(maxSpeed, engineCapacity, engineType), liftingCapacity_(liftingCapacity) {
	spdlog::debug("Truck costr with parametres: {0:d}, {1:f}, {2:s}, {3:d}", maxSpeed, engineCapacity, engineTypeToString(engineType), liftingCapacity);
};

void Truck::engineOn() const {
	spdlog::info("Truck engine is on");
}

void Truck::engineOff() const {
	spdlog::info("Truck engine is off");
}

std::string Truck::toString() const {
	spdlog::info("Truck's toString function");
	return Vehicle::toString() + " Lifting capacity: " + std::to_string(liftingCapacity_) + "kg";
}

Truck::~Truck() {
	spdlog::debug("Truck's destr");
}