#include "Car.h"

Car::Car(int maxSpeed, double engineCapacity, EngineType engineType, int seatsNumber) : Vehicle(maxSpeed, engineCapacity, engineType), numberOfSeats_(seatsNumber) {
	spdlog::debug("Car costr with parametres: {0:d}, {1:f}, {2:s}, {3:d}", maxSpeed, engineCapacity, engineTypeToString(engineType), seatsNumber);
};

void Car::engineOn() const {
	spdlog::info("Car engine is on");
}

void Car::engineOff() const {
	spdlog::info("Car engine is off");
}

std::string Car::toString() const {
	spdlog::info("Car's toString function");
	return Vehicle::toString() + " Number of seats: " + std::to_string(numberOfSeats_);
}

Car::~Car() {
	spdlog::debug("Car's destr");
}