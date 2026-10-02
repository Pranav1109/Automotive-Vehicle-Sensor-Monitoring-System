#pragma once

#include "Sensor.h"

#include <array>
#include <memory>

// Owns the vehicle's sensors and calculates an overall health status.
class Vehicle
{
public:
    Vehicle();

    void updateSensors(double currentSpeedKmh,
                       double steeringAngleDeg,
                       double throttlePercent,
                       double engineTempCelsius);
    SensorStatus checkVehicleHealth() const;

private:
    std::array<std::unique_ptr<Sensor>, 4> sensors_;
};
