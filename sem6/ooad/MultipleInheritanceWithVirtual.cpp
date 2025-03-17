#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "Class A" << endl;
    }
};

// Using virtual inheritance
class B : virtual public A {};
class C : virtual public A {};

class D : public B, public C {};

int main() {
    D obj;
    obj.show();  // ✅ No ambiguity - only one copy of A exists
    return 0;
}
