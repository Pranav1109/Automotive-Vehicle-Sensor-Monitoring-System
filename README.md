# Automotive Vehicle Sensor Monitoring System

A small C++17 console project that simulates four vehicle sensors, checks their reading ranges, tracks sensor and vehicle health, reports warnings, and logs status changes.

## Sensors

| Sensor | Valid range | Additional status rules |
| --- | --- | --- |
| Speed | 0-250 km/h | Out of range is a fault |
| Steering | -540 to +540 deg | Out of range is a fault |
| Throttle | 0-100% | Out of range is a fault |
| Engine temperature | 0-150 C | Warning above 110 C; fault above 120 C |

`Vehicle` owns its sensors through `std::unique_ptr<Sensor>`. The shared base-class interface lets it update, inspect, and report all sensor types uniformly. Sensors begin `OFFLINE`; an out-of-range reading or engine temperature above 120 C produces `FAULT`.

## Build and run

With CMake:

```sh
cmake -S . -B build
cmake --build build
```

Run `build/Debug/vehicle_sensor_monitor.exe` on a typical Windows Visual Studio build, or `./build/vehicle_sensor_monitor` on Linux and macOS. The executable runs normal, warning, fault, and recovery scenarios.

With a C++17 compiler directly:

```sh
g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinclude src/main.cpp src/Sensor.cpp src/Sensors.cpp src/Vehicle.cpp -o vehicle_sensor_monitor
```