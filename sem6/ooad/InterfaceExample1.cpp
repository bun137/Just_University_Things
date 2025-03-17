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
    // Pointer to interface	
    IShape* shape1 = new Circle(5); //Object created on Heap (manual new and delete needed), supports polymorphism
    shape1->draw();
    cout << "Area: " << shape1->area() << endl;

    IShape* shape2 = new Rectangle(4, 6);
    shape2->draw();
    cout << "Area: " << shape2->area() << endl;
	
    // Cleanup
    delete shape1;
    delete shape2;

    return 0;
}
