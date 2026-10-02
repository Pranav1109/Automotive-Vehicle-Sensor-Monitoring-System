#include "Sensor.h"

#include <iostream>
#include <utility>

std::string toString(SensorStatus status)
{
    switch (status)
    {
    case SensorStatus::NORMAL:
        return "NORMAL";
    case SensorStatus::WARNING:
        return "WARNING";
    case SensorStatus::FAULT:
        return "FAULT";
    case SensorStatus::OFFLINE:
        return "OFFLINE";
    }

    return "UNKNOWN";
}

Sensor::Sensor(std::string name, std::string unit, double minimum, double maximum)
    : name_(std::move(name)), unit_(std::move(unit)), minimum_(minimum), maximum_(maximum)
{
}

void Sensor::updateReading(double value)
{
    const SensorStatus previousStatus = status_;
    reading_ = value;
    hasReading_ = true;
    status_ = validate() ? determineStatus() : SensorStatus::FAULT;

    if (status_ != previousStatus)
    {
        logEvent("status changed from " + toString(previousStatus) + " to " + toString(status_));
    }
}

bool Sensor::validate() const
{
    return hasReading_ && reading_ >= minimum_ && reading_ <= maximum_;
}

SensorStatus Sensor::getStatus() const
{
    return status_;
}

std::string Sensor::generateWarning() const
{
    switch (status_)
    {
    case SensorStatus::WARNING:
        return getName() + ": reading is above the recommended operating range.";
    case SensorStatus::FAULT:
        return getName() + ": fault detected; check the sensor reading.";
    case SensorStatus::OFFLINE:
        return getName() + ": no reading received.";
    case SensorStatus::NORMAL:
        return {};
    }

    return {};
}

void Sensor::logEvent(const std::string& event) const
{
    std::cout << "[EVENT] " << name_ << ": " << event << '\n';
}

const std::string& Sensor::getName() const
{
    return name_;
}

const std::string& Sensor::getUnit() const
{
    return unit_;
}

double Sensor::getReading() const
{
    return reading_;
}

bool Sensor::hasReading() const
{
    return hasReading_;
}

SensorStatus Sensor::determineStatus() const
{
    return SensorStatus::NORMAL;
}
