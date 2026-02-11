#include <iostream>
using namespace std;

class Shallow {
public:
    int *data;

    // Constructor
    Shallow(int value) {
        data = new int(value);
    }

    // Shallow Copy Constructor
    Shallow(const Shallow &obj) {
        data = obj.data;   // Copies address only
    }

    void show() {
        cout << *data << endl;
    }
};

int main() {
    Shallow obj1(10);
    Shallow obj2 = obj1;   // Shallow copy

    *obj2.data = 20;       // Modify obj2

    cout << "Obj1 data: ";
    obj1.show();           // Also changes ❌
    cout << "Obj2 data: ";
    obj2.show();

    return 0;
}
