#include <iostream>
using namespace std;

// Shape Interface
class IShape {
public:
    virtual void draw() = 0;
    virtual double area() = 0;
    virtual ~IShape() {}
};

// Color Interface
class IColorable {
public:
    virtual void setColor(string color) = 0;
    virtual void getColor() = 0;
    virtual ~IColorable() {}
};

// Circle implementing both interfaces
class Circle : public IShape, public IColorable {
    double radius;
    string color;
public:
    Circle(double r) : radius(r) {}

    void draw() override {
        cout << "Drawing a Circle" << endl;
    }

    double area() override {
        return 3.14 * radius * radius;
    }

    void setColor(string c) override {
        color = c;
    }

    void getColor() override {
        cout << "Circle color: " << color << endl;
    }
};

int main() {
    Circle c(7);
    c.draw();
    c.setColor("Red");
    c.getColor();
    cout << "Area: " << c.area() << endl;

    return 0;
}
