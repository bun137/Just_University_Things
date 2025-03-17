#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "Class A" << endl;
    }
};

class B : public A {}; // Inherits from A
class C : public A {}; // Also inherits from A

class D : public B, public C {}; // Inherits from both B and C

int main() {
    D obj;
    // obj.show();  // ERROR: Ambiguity - Compiler doesn't know which A::show() to call
    obj.B::show();  // Works, explicitly calling show() from B
    obj.C::show();  // Works, explicitly calling show() from C
    return 0;
}
