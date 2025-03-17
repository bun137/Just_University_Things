#include <iostream>
using namespace std;

// Base class (Superclass)
class Engineer {
public:
    string name;
    int yearsOfExperience;

    Engineer(string name, int yearsOfExperience) {
        this->name = name;
        this->yearsOfExperience = yearsOfExperience;
    }

	virtual	void work() {
        cout << name << " is working as an engineer with " << yearsOfExperience << " years of experience." << endl;
    }
};
// Derived class (Software Engineer)
class SoftwareEngineer : public Engineer {
public:
    string programmingLanguage;
    SoftwareEngineer(string name, int yearsOfExperience, string programmingLanguage)
        : Engineer(name, yearsOfExperience) {
        this->programmingLanguage = programmingLanguage;
    }
    void code() {
        cout << name << " is coding in " << programmingLanguage << endl;
    }
};
// Main function to test inheritance
int main() {
    SoftwareEngineer softwareEngineer("Ram", 5, "C++");
    
    softwareEngineer.work();
    softwareEngineer.code();
    return 0;
}







