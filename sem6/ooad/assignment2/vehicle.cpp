#ifndef VEHICLE_RENTAL_SYSTEM_H
#define VEHICLE_RENTAL_SYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <ctime>
#include <iomanip>

enum class FuelType {
    ELECTRIC,
    PETROL,
    DIESEL
};

enum class TransmissionType {
    MANUAL,
    AUTOMATIC
};

enum class CarType {
    HATCHBACK,
    SEDAN,
    SUV
};

class Vehicle {
protected:
    std::string regnNumber;
    FuelType fuelType;
    double perDayRent;
    std::time_t rentalDate;

public:
    Vehicle(const std::string& regNum, FuelType fuel, double rent, std::time_t date)
        : regnNumber(regNum), fuelType(fuel), perDayRent(rent), rentalDate(date) {}

    virtual ~Vehicle() = default;

    virtual std::string getRegnNumber() const { return regnNumber; }
    virtual std::time_t getRentalDate() const { return rentalDate; }

    virtual void printDetails() const = 0;
};

class Car : public Vehicle {
private:
    TransmissionType transmissionType;
    CarType carType;
    int numberOfSeats;

public:
    Car(const std::string& regNum, FuelType fuel, double rent, std::time_t date,
        TransmissionType transmission, CarType type, int seats)
        : Vehicle(regNum, fuel, rent, date),
          transmissionType(transmission),
          carType(type),
          numberOfSeats(seats) {}

    void printDetails() const override {
        std::cout << "Car Details:" << std::endl;
        std::cout << "Registration Number: " << regnNumber << std::endl;
        std::cout << "Fuel Type: " << getFuelTypeString() << std::endl;
        std::cout << "Per Day Rent: Rs. " << perDayRent << std::endl;
        
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", std::localtime(&rentalDate));
        std::cout << "Rental Date: " << buffer << std::endl;
        
        std::cout << "Transmission Type: " << getTransmissionTypeString() << std::endl;
        std::cout << "Car Type: " << getCarTypeString() << std::endl;
        std::cout << "Number of Seats: " << numberOfSeats << std::endl;
    }

private:
    std::string getFuelTypeString() const {
        switch(fuelType) {
            case FuelType::ELECTRIC: return "Electric";
            case FuelType::PETROL: return "Petrol";
            case FuelType::DIESEL: return "Diesel";
            default: return "Unknown";
        }
    }

    std::string getTransmissionTypeString() const {
        switch(transmissionType) {
            case TransmissionType::MANUAL: return "Manual";
            case TransmissionType::AUTOMATIC: return "Automatic";
            default: return "Unknown";
        }
    }

    std::string getCarTypeString() const {
        switch(carType) {
            case CarType::HATCHBACK: return "Hatchback";
            case CarType::SEDAN: return "Sedan";
            case CarType::SUV: return "SUV";
            default: return "Unknown";
        }
    }
};

class Motorcycle : public Vehicle {
private:
    int engineDisplacement; // in cc
    double weight; // in kg

public:
    Motorcycle(const std::string& regNum, FuelType fuel, double rent, std::time_t date,
               int displacement, double vehicleWeight)
        : Vehicle(regNum, fuel, rent, date),
          engineDisplacement(displacement),
          weight(vehicleWeight) {}

    void printDetails() const override {
        std::cout << "Motorcycle Details:" << std::endl;
        std::cout << "Registration Number: " << regnNumber << std::endl;
        std::cout << "Fuel Type: " << getFuelTypeString() << std::endl;
        std::cout << "Per Day Rent: Rs. " << perDayRent << std::endl;
        
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", std::localtime(&rentalDate));
        std::cout << "Rental Date: " << buffer << std::endl;
        
        std::cout << "Engine Displacement: " << engineDisplacement << " cc" << std::endl;
        std::cout << "Weight: " << weight << " kg" << std::endl;
    }

private:
    std::string getFuelTypeString() const {
        switch(fuelType) {
            case FuelType::ELECTRIC: return "Electric";
            case FuelType::PETROL: return "Petrol";
            case FuelType::DIESEL: return "Diesel";
            default: return "Unknown";
        }
    }
};

class User {
private:
    std::string name;
    std::vector<std::shared_ptr<Vehicle>> rentedVehicles;

public:
    User(const std::string& userName) : name(userName) {}

    void rentVehicle(std::shared_ptr<Vehicle> vehicle) {
        rentedVehicles.push_back(vehicle);
    }

    void displayRentedVehicles() {
        std::cout << "Vehicles rented by " << name << ":" << std::endl;

        std::sort(rentedVehicles.begin(), rentedVehicles.end(), 
            [](const std::shared_ptr<Vehicle>& a, const std::shared_ptr<Vehicle>& b) {
                return a->getRentalDate() < b->getRentalDate();
            });

        for (const auto& vehicle : rentedVehicles) {
            vehicle->printDetails();
            std::cout << std::endl;
        }
    }
};

int main() {
    User user("John Doe");

    auto car1 = std::make_shared<Car>("KA01AB1234", FuelType::PETROL, 1500.0, 
        std::time(nullptr) - 86400, // Yesterday
        TransmissionType::AUTOMATIC, CarType::SEDAN, 4);

    auto motorcycle1 = std::make_shared<Motorcycle>("MH02CD5678", FuelType::DIESEL, 800.0, 
        std::time(nullptr) - 172800, // Two days ago
        150, 180.5);

    auto car2 = std::make_shared<Car>("TN03EF9012", FuelType::ELECTRIC, 2000.0, 
        std::time(nullptr), // Today
        TransmissionType::MANUAL, CarType::HATCHBACK, 2);

    user.rentVehicle(car1);
    user.rentVehicle(motorcycle1);
    user.rentVehicle(car2);

    user.displayRentedVehicles();

    return 0;
}

#endif // VEHICLE_RENTAL_SYSTEM_H
