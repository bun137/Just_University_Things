#include <iostream>
using namespace std;

// Base class (Superclass)
class Animal {
public:
  // Method in the base class
  virtual void sound() { cout << "Animal makes a sound" << endl; }
};

// Derived class (Subclass)
class Dog : public Animal {
public:
  // Overriding the sound() method
  void sound() override {
    /*
    the program will work even without the
    override keyword but it is used for following reasons:
    1. Ensures correctness: Catch overriding errors during compilation.
    2. Improves maintainability: Makes the intent clear to others reading your
    code.
    3. Prevents unexpected behavior: Avoids silent bugs caused by mismatched
    signatures.
    */
    cout << "Dog barks" << endl;
  }
};

int main() {
  Animal *animal = new Animal();
  animal->sound(); // Output: Animal makes a sound

  Dog *dog = new Dog();
  dog->sound(); // Output: Dog barks

  // Demonstrating runtime polymorphism
  Animal *ref = new Dog();
  ref->sound(); // Output: Dog barks

  delete animal;
  delete dog;
  delete ref;

  return 0;
}
