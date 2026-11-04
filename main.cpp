#include "ParkingSystem.h"
#include <iostream>
#include <limits>
#include <string>

int main() {
    ParkingSystem parking(10);
    HourlyPricing pricing(2.0);
    FlatRatePricing flatPricing(5.0);
    parking.load("parking_data.txt");

    while (true) {
        std::cout << "\n=== Smart Parking Management System ===\n"
                  << "1. Park a Car\n"
                  << "2. Remove a Car\n"
                  << "3. Show Parking Status\n"
                  << "4. Calculate Parking Fee\n"
                  << "5. Exit\n"
                  << "Choose an option: ";
        int choice;
        if (!(std::cin >> choice)) {
            if (std::cin.eof()) break;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid option.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 5) break;
        if (choice == 1 || choice == 2) {
            std::string plate;
            std::cout << "Enter license plate: ";
            std::getline(std::cin, plate);
            bool ok = choice == 1 ? parking.park(plate) : parking.remove(plate);
            std::cout << (ok ? "Operation successful.\n" : "Operation failed. Check plate or capacity.\n");
            if (ok && !parking.save("parking_data.txt")) std::cout << "Warning: could not save data.\n";
        } else if (choice == 3) {
            std::cout << "Available: " << parking.available() << "/" << parking.capacity() << '\n';
            for (const auto& spot : parking.spots())
                std::cout << "Spot " << spot.number << ": " << (spot.occupied() ? spot.plate : "Available") << '\n';
        } else if (choice == 4) {
            
std::cout << "1. Hourly Pricing\n";
std::cout << "2. Flat Rate Pricing\n";
std::cout << "Choose pricing type: ";
int pricingChoice;
if (!(std::cin >> pricingChoice)) {
    if (std::cin.eof()) break;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid pricing type.\n";
    continue;
}
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
if (pricingChoice != 1 && pricingChoice != 2) {
    std::cout << "Invalid pricing type.\n";
    continue;
}

            std::cout << "Hours parked: ";
            int hours;
            if (!(std::cin >> hours)) {
                if (std::cin.eof()) break;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid hours.\n";
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (hours <= 0) std::cout << "Hours must be positive.\n";
         
else {
    const PricingStrategy& selectedPricing =
        (pricingChoice == 1)
            ? static_cast<const PricingStrategy&>(pricing)
            : static_cast<const PricingStrategy&>(flatPricing);

    std::cout << "Fee: " << selectedPricing.calculate(hours) << "\n";
}

        } else {
            std::cout << "Invalid option.\n";
        }
    }
    if (!parking.save("parking_data.txt")) std::cerr << "Warning: could not save data.\n";
    std::cout << "Goodbye!\n";
}
