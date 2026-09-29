#include "Vehicle.h"

#include <iostream>

int main()
{
    Vehicle vehicle;

    std::cout << "Automotive Vehicle Sensor Monitoring System\n";
    vehicle.checkVehicleHealth();

    std::cout << "\nScenario: normal driving\n";
    vehicle.updateSensors(72.0, 15.0, 28.0, 96.0);
    vehicle.checkVehicleHealth();

    std::cout << "\nScenario: engine temperature warning\n";
    vehicle.updateSensors(72.0, 15.0, 28.0, 115.0);
    vehicle.checkVehicleHealth();

    std::cout << "\nScenario: engine temperature fault and invalid speed\n";
    vehicle.updateSensors(280.0, 15.0, 28.0, 125.0);
    vehicle.checkVehicleHealth();

    std::cout << "\nScenario: readings recover\n";
    vehicle.updateSensors(64.0, -20.0, 18.0, 88.0);
    vehicle.checkVehicleHealth();

    return 0;
}