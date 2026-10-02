#include "Sensors.h"

SpeedSensor::SpeedSensor()
    : Sensor("Speed Sensor", "km/h", 0.0, 250.0)
{
}

SteeringSensor::SteeringSensor()
    : Sensor("Steering Sensor", "deg", -540.0, 540.0)
{
}

ThrottleSensor::ThrottleSensor()
    : Sensor("Throttle Sensor", "%", 0.0, 100.0)
{
}

EngineTempSensor::EngineTempSensor()
    : Sensor("Engine Temp Sensor", "C", 0.0, 150.0)
{
}

SensorStatus EngineTempSensor::determineStatus() const
{
    if (getReading() > 120.0)
    {
        return SensorStatus::FAULT;
    }

    if (getReading() > 110.0)
    {
        return SensorStatus::WARNING;
    }

    return SensorStatus::NORMAL;
}
