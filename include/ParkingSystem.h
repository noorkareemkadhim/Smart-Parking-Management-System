#pragma once
#include <ctime>
#include <string>
#include <vector>
/**
 * @brief Represents a single parking spot.
 *
 * Stores the spot number, license plate, and vehicle entry time.
 */
struct ParkingSpot {
    int number;
    std::string plate;
    std::time_t entryTime = 0;
    bool occupied() const { return !plate.empty(); }
};

/**
 * @brief Abstract interface for parking fee calculation.
 *
 * Uses the Strategy design pattern to support different pricing methods.
 */
class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    virtual double calculate(int hours) const = 0;
};
/**
 * @brief Calculates parking fees based on the number of hours.
 */
class HourlyPricing : public PricingStrategy {
public:
    explicit HourlyPricing(double rate = 2.0) : rate_(rate) {}
    double calculate(int hours) const override;
private:
    double rate_;
};
/**
 * @brief Calculates a fixed parking fee regardless of parking duration.
 */
class FlatRatePricing : public PricingStrategy {
public:
    explicit FlatRatePricing(double fee = 5.0) : fee_(fee) {}
    double calculate(int hours) const override;

private:
    double fee_;
};
/**
 * @brief Manages parking spaces and vehicle operations.
 *
 * Supports parking, removal, searching, fee duration,
 * and saving/loading parking data.
 */
class ParkingSystem {
public:
/**
 * @brief Creates a parking system with a specified capacity.
 * @param capacity Maximum number of parking spaces.
 */
    explicit ParkingSystem(int capacity);
    /**
 * @brief Parks a vehicle in an available parking spot.
 * @param plate License plate of the vehicle.
 * @return True if parking succeeds, false otherwise.
 */
    bool park(const std::string& plate);
    /**
 * @brief Removes a vehicle from the parking system.
 * @param plate License plate of the vehicle.
 * @return True if the vehicle is removed, false otherwise.
 */
    bool remove(const std::string& plate);
    /**
 * @brief Searches for a vehicle by its license plate.
 * @param plate License plate of the vehicle.
 * @return Parking spot number if found, or -1 if not found.
 */
    int findCar(const std::string& plate) const;
    /**
 * @brief Calculates how long a vehicle has been parked.
 * @param plate License plate of the vehicle.
 * @return Parking duration in hours, or -1 if not found.
 */
    int parkingHours(const std::string& plate) const;
    /**
 * @brief Returns the number of available parking spaces.
 * @return Number of free parking spaces.
 */
    int available() const;
    /**
 * @brief Returns the number of occupied parking spaces.
 * @return Number of occupied parking spaces.
 */
    int occupiedCount() const;
    /**
 * @brief Returns the total capacity of the parking system.
 * @return Maximum number of parking spaces.
 */
    int capacity() const;
    /**
 * @brief Returns all parking spots in the system.
 * @return Constant reference to the list of parking spots.
 */
    const std::vector<ParkingSpot>& spots() const;
    /**
 * @brief Saves parking data to a file.
 * @param path Path to the file where data will be saved.
 * @return True if saving succeeds, false otherwise.
 */
    bool save(const std::string& path) const;
    /**
 * @brief Loads parking data from a file.
 * @param path Path to the file containing saved parking data.
 * @return True if loading succeeds, false otherwise.
 */
    bool load(const std::string& path);
private:
    std::vector<ParkingSpot> spots_;
};
