#include "Vehicle.h"

#include "Sensors.h"

#include <iomanip>
#include <iostream>

namespace
{
int severity(SensorStatus status)
{
    switch (status)
    {
    case SensorStatus::NORMAL:
        return 0;
    case SensorStatus::WARNING:
        return 1;
    case SensorStatus::OFFLINE:
        return 2;
    case SensorStatus::FAULT:
        return 3;
    }

    return 3;
}
}

Vehicle::Vehicle()
    : sensors_{std::make_unique<SpeedSensor>(),
               std::make_unique<SteeringSensor>(),
               std::make_unique<ThrottleSensor>(),
               std::make_unique<EngineTempSensor>()}
{
}

void Vehicle::updateSensors(double currentSpeedKmh,
                            double steeringAngleDeg,
                            double throttlePercent,
                            double engineTempCelsius)
{
    const std::array<double, 4> readings{
        currentSpeedKmh,
        steeringAngleDeg,
        throttlePercent,
        engineTempCelsius};

    for (std::size_t index = 0; index < sensors_.size(); ++index)
    {
        sensors_[index]->updateReading(readings[index]);
    }
}

SensorStatus Vehicle::checkVehicleHealth() const
{
    SensorStatus vehicleStatus = SensorStatus::NORMAL;

    for (const auto& sensor : sensors_)
    {
        if (severity(sensor->getStatus()) > severity(vehicleStatus))
        {
            vehicleStatus = sensor->getStatus();
        }
    }

    std::cout << "\nVehicle health: " << toString(vehicleStatus) << '\n';
    for (const auto& sensor : sensors_)
    {
        std::cout << "  " << std::left << std::setw(20) << sensor->getName() << " ";
        if (sensor->hasReading())
        {
            std::cout << std::right << std::fixed << std::setprecision(1)
                      << sensor->getReading() << ' ' << sensor->getUnit();
        }
        else
        {
            std::cout << "--";
        }

        std::cout << " | " << toString(sensor->getStatus()) << '\n';
        const std::string warning = sensor->generateWarning();
        if (!warning.empty())
        {
            std::cout << "    " << warning << '\n';
        }
    }

    return vehicleStatus;
}