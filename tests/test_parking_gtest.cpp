
#include "ParkingSystem.h"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(ParkingSystemTest, InitialCapacity) {
    ParkingSystem p(2);

    EXPECT_EQ(p.capacity(), 2);
    EXPECT_EQ(p.available(), 2);
}

TEST(ParkingSystemTest, PreventDuplicateParking) {
    ParkingSystem p(2);

    EXPECT_TRUE(p.park("ABC123"));
    EXPECT_FALSE(p.park("ABC123"));
    EXPECT_EQ(p.available(), 1);
}

TEST(PricingTest, InvalidParkingHours) {
    HourlyPricing pricing(3.0);

    EXPECT_THROW(pricing.calculate(0), std::invalid_argument);
}
