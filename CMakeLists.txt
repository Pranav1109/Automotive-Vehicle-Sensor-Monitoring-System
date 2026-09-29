cmake_minimum_required(VERSION 3.16)
project(AutomotiveVehicleSensorMonitoring LANGUAGES CXX)

add_executable(vehicle_sensor_monitor
    src/main.cpp
    src/Sensor.cpp
    src/Sensors.cpp
    src/Vehicle.cpp
)

target_include_directories(vehicle_sensor_monitor PRIVATE include)
target_compile_features(vehicle_sensor_monitor PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(vehicle_sensor_monitor PRIVATE /W4)
else()
    target_compile_options(vehicle_sensor_monitor PRIVATE -Wall -Wextra -Wpedantic)
endif()