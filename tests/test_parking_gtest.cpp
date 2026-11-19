
#include "ParkingSystem.h"
#include <gtest/gtest.h>

TEST(ParkingSystemTest, InitialCapacity) {
    ParkingSystem p(2);

    EXPECT_EQ(p.capacity(), 2);
    EXPECT_EQ(p.available(), 2);
}
