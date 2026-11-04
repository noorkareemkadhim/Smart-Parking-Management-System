#pragma once
#include <string>
#include <vector>

struct ParkingSpot {
    int number;
    std::string plate;
    bool occupied() const { return !plate.empty(); }
};

// Strategy pattern: pricing can change without modifying ParkingSystem.
class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    virtual double calculate(int hours) const = 0;
};

class HourlyPricing : public PricingStrategy {
public:
    explicit HourlyPricing(double rate = 2.0) : rate_(rate) {}
    double calculate(int hours) const override;
private:
    double rate_;
};

class FlatRatePricing : public PricingStrategy {
public:
    explicit FlatRatePricing(double fee = 5.0) : fee_(fee) {}
    double calculate(int hours) const override;

private:
    double fee_;
};
class ParkingSystem {
public:
    explicit ParkingSystem(int capacity);
    bool park(const std::string& plate);
    bool remove(const std::string& plate);
    int available() const;
    int capacity() const;
    const std::vector<ParkingSpot>& spots() const;
    bool save(const std::string& path) const;
    bool load(const std::string& path);
private:
    std::vector<ParkingSpot> spots_;
};
