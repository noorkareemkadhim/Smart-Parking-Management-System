cmake_minimum_required(VERSION 3.16)
project(SmartParkingManagementSystem LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(parking_lib src/ParkingSystem.cpp)
target_include_directories(parking_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(smart_parking main.cpp)
target_link_libraries(smart_parking PRIVATE parking_lib)
enable_testing()
add_executable(parking_tests tests/test_parking.cpp)
target_link_libraries(parking_tests PRIVATE parking_lib)
add_test(NAME ParkingTests COMMAND parking_tests)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
FetchContent_MakeAvailable(googletest)
add_executable(parking_gtest tests/test_parking_gtest.cpp)
target_link_libraries(parking_gtest PRIVATE parking_lib GTest::gtest_main)
add_test(NAME ParkingGoogleTest COMMAND parking_gtest)





