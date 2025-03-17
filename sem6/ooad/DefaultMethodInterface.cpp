#include <iostream>
using namespace std;

// Interface with a default method
class IShape {
public:
    virtual void draw() = 0;
    virtual double area() = 0;

    // Default implementation
    void printShape() {
        cout << "This is a shape!" << endl;
    }

    virtual ~IShape() {}
};

// Rectangle implementing IShape
class Rectangle : public IShape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }

    double area() override {
        return width * height;
    }
};

int main() {
    Rectangle rect(5, 10);
    rect.printShape(); // Default method
    rect.draw();
    cout << "Area: " << rect.area() << endl;

    return 0;
}
