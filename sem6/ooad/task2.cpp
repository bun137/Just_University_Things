#include <iostream>
#include <string>
#include <sstream>

class Cylinder {
private:
    int size;

public:
    Cylinder(int size = 0) : size(size) {}

    int getSize() const {
        return size;
    }
};

class Engine {
private:
    int horsepower;
    Cylinder cylinder;

public:
    Engine(int hp, int cylinderSize = 0)
        : horsepower(hp), cylinder(cylinderSize) {}

    int getHorsepower() const {
        return horsepower;
    }

    int getCylinderSize() const {
        return cylinder.getSize();
    }
};

class Car {
private:
    std::string name;
    Engine engine;

public:
    Car(const std::string& carName, int horsepower, int cylinderSize)
        : name(carName), engine(horsepower, cylinderSize) {}

    std::string getName() const {
        return name;
    }

    int getEngineHorsepower() const {
        return engine.getHorsepower();
    }

    int getEngineCylinderSize() const {
        return engine.getCylinderSize();
    }
};
int main() {
    std::cout << "Enter car details on one line:\n"
              << "[carName horsepower [cylinderSize]]\n\n"
              << "Examples:\n"
              << "  Tesla 300\n"
              << "  BMW 250 2\n\n";

    std::cout << "Input: ";

    std::string line;
    if (!std::getline(std::cin, line) || line.empty()) {
        std::cerr << "No input provided.\n";
        return 1;
    }

    std::istringstream iss(line);
    std::string carName;
    int horsepower = 0;
    int cylinderSize = 0;

    if (!(iss >> carName >> horsepower)) {
        std::cerr << "Invalid input format (need at least carName + horsepower).\n";
        return 1;
    }

    if (!(iss >> cylinderSize)) {
        cylinderSize = 0;
    }

    Car myCar(carName, horsepower, cylinderSize);

    std::cout << "The " << myCar.getName() 
              << " has an engine of " << myCar.getEngineHorsepower()
              << " horsepower containing "
              << myCar.getEngineCylinderSize()
              << " size cylinder.\n";

    return 0;
}
