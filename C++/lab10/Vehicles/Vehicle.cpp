#include "Vehicle.h"

void Vehicle::setMaxSpeed(const int& maxSpeed) {
	maxSpeed_ = maxSpeed;
}

void Vehicle::setEngineCapacity(const double& engineCapacity) {
	engineCapacity_ = engineCapacity;
}

void Vehicle::setEngineType(const EngineType& engineType) {
	engineType_ = engineType;
}

int Vehicle::getMaxSpeed() const
{
	return maxSpeed_;
}
double Vehicle::getEngineCapacity() const
{
	return engineCapacity_;
}
std::string Vehicle::getEngineType() const
{
	return engineTypeToString(engineType_);
}

std::string Vehicle::toString() const 
{
	return  "Max speed = " + std::to_string(maxSpeed_) + "km/h, Engine capacity: " +
		std::to_string(engineCapacity_) + "l, Engine type: " + engineTypeToString(engineType_) + '\n';
}

std::string engineTypeToString(EngineType engineType)
{
	std::vector<std::string> engineTypeNames{ "PETROL", "DIESEL", "GAS", "ELECTRIC" };
	return engineTypeNames[engineType];
}

Vehicle::~Vehicle() {
	spdlog::debug("Vehicle destr");
}

Vehicle::Vehicle(const Vehicle& other)
{
	maxSpeed_ = other.maxSpeed_;
	engineCapacity_ = other.engineCapacity_;
	engineType_ = other.engineType_;
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	maxSpeed_ = other.maxSpeed_;
	engineCapacity_ = other.engineCapacity_;
	engineType_ = other.engineType_;
	return *this;
}

Vehicle::Vehicle(Vehicle&& moved) noexcept
{
	maxSpeed_ = std::move(moved.maxSpeed_);
	engineCapacity_ = std::move(moved.engineCapacity_);
	engineType_ = std::move(moved.engineType_);
}

Vehicle& Vehicle::operator=(Vehicle&& moved) noexcept
{
	maxSpeed_ = std::move(moved.maxSpeed_);
	engineCapacity_ = std::move(moved.engineCapacity_);
	engineType_ = std::move(moved.engineType_);
	return *this;
}