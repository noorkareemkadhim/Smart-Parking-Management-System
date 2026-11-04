#include "ParkingSystem.h"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace {
bool validPlate(const std::string& plate) {
    return !plate.empty() && plate.size() <= 20 && plate.find_first_of("\r\n\t") == std::string::npos;
}
}

double HourlyPricing::calculate(int hours) const {
    if (hours <= 0) throw std::invalid_argument("Hours must be positive");
    return rate_ * hours;
}

double FlatRatePricing::calculate(int hours) const {
    if (hours <= 0)
        throw std::invalid_argument("Hours must be positive");
    return fee_;
}

ParkingSystem::ParkingSystem(int capacity) {
    if (capacity <= 0) throw std::invalid_argument("Capacity must be positive");
    for (int i = 1; i <= capacity; ++i) spots_.push_back({i, ""});
}

bool ParkingSystem::park(const std::string& plate) {
    if (!validPlate(plate)) return false;
    for (const auto& spot : spots_) if (spot.plate == plate) return false;
    for (auto& spot : spots_) {
        if (!spot.occupied()) { spot.plate = plate; return true; }
    }
    return false;
}

bool ParkingSystem::remove(const std::string& plate) {
    for (auto& spot : spots_) {
        if (spot.plate == plate && spot.occupied()) { spot.plate.clear(); return true; }
    }
    return false;
}

int ParkingSystem::available() const {
    int count = 0;
    for (const auto& spot : spots_) if (!spot.occupied()) ++count;
    return count;
}

int ParkingSystem::capacity() const { return static_cast<int>(spots_.size()); }
const std::vector<ParkingSpot>& ParkingSystem::spots() const { return spots_; }

bool ParkingSystem::save(const std::string& path) const {
    std::ofstream out(path, std::ios::trunc);
    if (!out) return false;
    out << spots_.size() << '\n';
    for (const auto& spot : spots_) out << std::quoted(spot.plate) << '\n';
    return static_cast<bool>(out);
}

bool ParkingSystem::load(const std::string& path) {
    std::ifstream in(path);
    if (!in) return false;
    int capacity = 0;
    if (!(in >> capacity) || capacity != this->capacity()) return false;
    std::vector<ParkingSpot> loaded;
    for (int i = 1; i <= capacity; ++i) {
        std::string plate;
        if (!(in >> std::quoted(plate))) return false;
        if (!plate.empty() && !validPlate(plate)) return false;
        for (const auto& spot : loaded) if (!plate.empty() && spot.plate == plate) return false;
        loaded.push_back({i, plate});
    }
    std::string extra;
    if (in >> extra) return false;
    spots_ = std::move(loaded);
    return true;
}
