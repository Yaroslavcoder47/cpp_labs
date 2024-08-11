#include <iostream>
#include "spdlog/spdlog.h"
#include "Vehicle.h"
#include "Car.h"
#include "ElectricVehicle.h"
#include "Motorcycle.h"
#include "Truck.h"
#include "ElectricCar.h"

using std::cin;
using std::cout;
using std::string;

int main()
{
	spdlog::set_level(spdlog::level::debug);
	spdlog::info("Program starts");
	ElectricCar car(140, 1.5, PETROL, 5, 400);
	car.engineOff();
	cout << car.toString() << '\n';

	spdlog::info("Program ends");
	return 0;
}