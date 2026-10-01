#pragma once

#include <string>

enum class SensorStatus
{
    NORMAL,
    WARNING,
    FAULT,
    OFFLINE
};

std::string toString(SensorStatus status);

// Base class for a vehicle sensor with a valid range and health status.
class Sensor
{
public:
    virtual ~Sensor() = default;

    void updateReading(double value);
    bool validate() const;
    SensorStatus getStatus() const;
    std::string generateWarning() const;
    void logEvent(const std::string& event) const;

    const std::string& getName() const;
    const std::string& getUnit() const;
    double getReading() const;
    bool hasReading() const;

protected:
    Sensor(std::string name, std::string unit, double minimum, double maximum);
    virtual SensorStatus determineStatus() const;

private:
    std::string name_;
    std::string unit_;
    double minimum_;
    double maximum_;
    double reading_ = 0.0;
    bool hasReading_ = false;
    SensorStatus status_ = SensorStatus::OFFLINE;
};
