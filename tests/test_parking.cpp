#include "ParkingSystem.h"
#include <cassert>
#include <cstdio>
#include <stdexcept>

int main() {
    ParkingSystem p(2);
    assert(p.capacity() == 2);
    assert(p.available() == 2);
    assert(p.park("ABC123"));
    assert(!p.park("ABC123"));
    assert(p.park("XYZ789"));
    assert(!p.park("FULL"));
    assert(p.available() == 0);
    assert(p.remove("ABC123"));
    assert(!p.remove("ABC123"));
    assert(p.available() == 1);
    assert(!p.park(""));
    assert(!p.park("   "));
    assert(p.save("parking_test_data.txt"));
    ParkingSystem loaded(2);
    assert(loaded.load("parking_test_data.txt"));
    assert(loaded.available() == 1);
    assert(loaded.spots()[1].plate == "XYZ789");
    std::remove("parking_test_data.txt");
    HourlyPricing pricing(3.0);
    assert(pricing.calculate(2) == 6.0);
    bool threw = false;
    try { pricing.calculate(0); } catch (const std::invalid_argument&) { threw = true; }
   assert(threw);

FlatRatePricing flatPricing(5.0);
assert(flatPricing.calculate(3) == 5.0);
assert(flatPricing.calculate(10) == 5.0);
assert(p.findCar("XYZ789") == 2);
assert(p.findCar("ABC123") == -1);
assert(p.findCar("NOTFOUND") == -1);
assert(p.occupiedCount() == 1);
}