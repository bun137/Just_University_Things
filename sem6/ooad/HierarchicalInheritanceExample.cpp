#include <iostream>
#include <string>
using namespace std;

// Base class
class Engineer {
protected:
    string name;

public:
    Engineer(string name) : name(name) {}

    void work() {
        cout << name << " is working as a general engineer." << endl;
    }
};

// Derived class 1: Software Engineer
class SoftwareEngineer : public Engineer {
protected:
    string programmingLanguage;

public:
    SoftwareEngineer(string name, string programmingLanguage)
        : Engineer(name), programmingLanguage(programmingLanguage) {}

    void code() {
        cout << name << " is coding in " << programmingLanguage << "." << endl;
    }
};

// Derived class 2: Civil Engineer
class CivilEngineer : public Engineer {
protected:
    string projectType;

public:
    CivilEngineer(string name, string projectType)
        : Engineer(name), projectType(projectType) {}

    void manageProject() {
        cout << name << " is managing a " << projectType << " project." << endl;
    }
};

// Main function to test the hierarchy
int main() {
    // Create instances of the derived classes
    SoftwareEngineer softwareEngineer("Ram", "C++");
    CivilEngineer civilEngineer("Krishna", "Bridge");

    // Call methods from the base class and derived classes
    softwareEngineer.work(); // From Engineer
    softwareEngineer.code(); // From SoftwareEngineer
    civilEngineer.work(); // From Engineer
    civilEngineer.manageProject(); // From CivilEngineer

    return 0;
}
