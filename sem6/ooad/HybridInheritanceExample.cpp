#include <iostream>
#include <string>
using namespace std;

// Base class
class Engineer {
protected:
    string name;
    int experience;

public:
    Engineer(string name, int experience) : name(name), experience(experience) {}

    void showDetails() {
        cout << "Engineer Name: " << name << ", Experience: " << experience << " years." << endl;
    }
};

// Derived class 1 (Hierarchical Inheritance from Engineer)
class SoftwareEngineer : virtual public Engineer {
protected:
    string programmingLanguage;

public:
    SoftwareEngineer(string name, int experience, string programmingLanguage)
        : Engineer(name, experience), programmingLanguage(programmingLanguage) {}

    void developSoftware() {
        cout << name << " is coding in " << programmingLanguage << "." << endl;
    }
};

// Derived class 2 (Hierarchical Inheritance from Engineer)
class CivilEngineer : virtual public Engineer {
protected:
    string projectType;

public:
    CivilEngineer(string name, int experience, string projectType)
        : Engineer(name, experience), projectType(projectType) {}

    void designStructure() {
        cout << name << " is working on a " << projectType << " project." << endl;
    }
};

// Derived class from both SoftwareEngineer and CivilEngineer (Multiple Inheritance)
class EngineeringManager : public SoftwareEngineer, public CivilEngineer {
private:
    int teamSize;

public:
    EngineeringManager(string name, int experience, string programmingLanguage, string projectType, int teamSize)
        : Engineer(name, experience), 
          SoftwareEngineer(name, experience, programmingLanguage), 
          CivilEngineer(name, experience, projectType), 
          teamSize(teamSize) {}

    void manageTeam() {
        cout << name << " is managing a team of " << teamSize << " engineers." << endl;
    }

    void showAllSkills() {
        SoftwareEngineer::showDetails();  // Avoiding ambiguity by specifying SoftwareEngineer scope
        developSoftware();
        designStructure();
        manageTeam();
    }
};

// Main function to demonstrate hybrid inheritance
int main() {
    // Create an instance of EngineeringManager
    EngineeringManager manager("Arya", 10, "C++", "Skyscraper", 20);

    // Show skills and details
    manager.showAllSkills();

    return 0;
}
