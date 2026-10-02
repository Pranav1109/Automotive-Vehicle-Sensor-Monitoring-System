#pragma once

#include "Sensor.h"

// Measures vehicle speed in kilometers per hour.
class SpeedSensor final : public Sensor
{
public:
    SpeedSensor();
};

// Measures steering wheel angle in degrees from center.
class SteeringSensor final : public Sensor
{
public:
    SteeringSensor();
};

// Measures throttle position as a percentage.
class ThrottleSensor final : public Sensor
{
public:
    ThrottleSensor();
};

// Measures engine temperature and applies warning and fault thresholds.
class EngineTempSensor final : public Sensor
{
public:
    EngineTempSensor();

protected:
    SensorStatus determineStatus() const override;
};
