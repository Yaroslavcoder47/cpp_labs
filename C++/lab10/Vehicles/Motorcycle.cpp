#include "Motorcycle.h"

Motorcycle::Motorcycle(int maxSpeed, double engineCapacity, EngineType engineType, std::string country) : Vehicle(maxSpeed, engineCapacity, engineType), country_(country) {
	spdlog::debug("Motorcycle costr with parametres: {0:d}, {1:f}, {2:s}, {3:s}", maxSpeed, engineCapacity, engineTypeToString(engineType), country);
};

void Motorcycle::engineOn() const {
	spdlog::info("Motorcycle engine is on");
}

void Motorcycle::engineOff() const {
	spdlog::info("Motorcycle engine is off");
}

std::string Motorcycle::toString() const {
	spdlog::info("Motorcycle's toString function");
	return Vehicle::toString() + " Country: " + country_;
}

Motorcycle::~Motorcycle() {
	spdlog::debug("Motorcycle's destr");
}