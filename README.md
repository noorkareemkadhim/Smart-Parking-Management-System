# Smart Parking Management System

A console-based C++17 parking management project for a software development/design patterns course.

## Features
- Park a car in the first available spot (10 spots by default)
- Prevent duplicate license plates
- Remove a parked car
- Display occupied and available spots
- Automatically calculate parking fees based on parking duration using HourlyPricing or FlatRatePricing
- Save and restore parking state from a local text file
- Automated unit tests with CTest
- Search for a parked car by license plate
- Automatically calculate parking duration

## Design pattern
**Strategy Pattern**: `PricingStrategy` defines the pricing interface. `HourlyPricing` calculates fees per hour, while `FlatRatePricing` uses a fixed fee. This allows different pricing methods without changing the parking system logic.

## Build and run (MSYS2 UCRT64)
From the project directory:

```bash
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
./build/smart_parking.exe
```

If CMake is not available in MSYS2, you can compile directly:

```bash
g++ -std=c++17 -Iinclude main.cpp src/ParkingSystem.cpp -o parking.exe
./parking.exe
```

## Tests
```bash
ctest --test-dir build --output-on-failure
```
The project includes both CTest and GoogleTest for automated testing.

Or without CMake:
```bash
g++ -std=c++17 -Iinclude tests/test_parking.cpp src/ParkingSystem.cpp -o parking_tests.exe
./parking_tests.exe
```

## Project structure
- `main.cpp`: menu and user interaction
- `include/ParkingSystem.h`: declarations and pricing strategy interface
- `src/ParkingSystem.cpp`: parking operations and persistence
- `tests/test_parking_gtest.cpp`: automated unit tests using GoogleTest
- `tests/test_parking.cpp`: automated tests
- `CMakeLists.txt`: build and test configuration

## Notes
- Pricing uses demonstration units, not a real currency.
- The project is a teaching prototype, not a production parking payment system.
- All changes should be committed when a real feature, fix, or test is completed.
