#include <iostream>
using namespace std;

// Interface (Abstract Class with Pure Virtual Functions)
class IShape {
public:
    // Pure virtual function (must be overridden)
    virtual void draw() = 0;
    
    // Another pure virtual function
    virtual double area() = 0;

    // Virtual destructor (best practice)
    virtual ~IShape() {}
};

// Derived class implementing the interface
class Circle : public IShape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    // Overriding draw method
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }

    // Overriding area method
    double area() override {
        return 3.14 * radius * radius;
    }
};

// Another derived class implementing the interface
class Rectangle : public IShape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Overriding draw method
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }

    // Overriding area method
    double area() override {
        return width * height;
    }
};

// Main function to demonstrate interface usage
int main() {
    
	Circle c(5); // Object created on stack, no new keyword, no polymorphism
	c.draw();
	cout << "Area: " << c.area() << endl;
    
	Rectangle r(5,10);
	r.draw();
	cout << "Area: " << r.area() << endl;

    return 0;
}
