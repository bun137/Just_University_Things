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

// Derived class
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

// Further derived class
class FullStackEngineer : public SoftwareEngineer {
private:
    string framework;

public:
    FullStackEngineer(string name, string programmingLanguage, string framework)
        : SoftwareEngineer(name, programmingLanguage), framework(framework) {}

    void designFrontend() {
        cout << name << " is designing a frontend using " << framework << "." << endl;
    }

    void manageBackend() {
        cout << name << " is managing the backend in " << programmingLanguage << "." << endl;
    }
};

// Main function
int main() {
    // Create an instance of FullStackEngineer
    FullStackEngineer engineer("Ram", "C++", "React");

    // Call methods from all levels of the hierarchy
    engineer.work();           // From Engineer
    engineer.code();           // From SoftwareEngineer
    engineer.designFrontend(); // From FullStackEngineer
    engineer.manageBackend();  // From FullStackEngineer

    return 0;
}
