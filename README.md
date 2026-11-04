# Smart Parking Management System

A console-based C++17 parking management project for a software development/design patterns course.

## Features
- Park a car in the first available spot (10 spots by default)
- Prevent duplicate license plates
- Remove a parked car
- Display occupied and available spots
- Calculate a fee using a configurable hourly pricing strategy
- Save and restore parking state from a local text file
- Automated unit tests with CTest

## Design pattern
**Strategy Pattern**: `PricingStrategy` defines the pricing interface and `HourlyPricing` implements an hourly fee policy. A future version can add daily or discounted pricing without changing the parking logic.

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

Or without CMake:
```bash
g++ -std=c++17 -Iinclude tests/test_parking.cpp src/ParkingSystem.cpp -o parking_tests.exe
./parking_tests.exe
```

## Project structure
- `main.cpp`: menu and user interaction
- `include/ParkingSystem.h`: declarations and pricing strategy interface
- `src/ParkingSystem.cpp`: parking operations and persistence
- `tests/test_parking.cpp`: automated tests
- `CMakeLists.txt`: build and test configuration

## Notes
- Pricing uses demonstration units, not a real currency.
- The project is a teaching prototype, not a production parking payment system.
- All changes should be committed when a real feature, fix, or test is completed.
