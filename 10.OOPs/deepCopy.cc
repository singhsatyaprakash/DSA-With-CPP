#include <iostream>
using namespace std;

class Deep {
public:
    int *data;

    // Constructor
    Deep(int value) {
        data = new int(value);
    }

    // Deep Copy Constructor
    Deep(const Deep &obj) {
        data = new int(*obj.data); // Allocate new memory
    }

    void show() {
        cout << *data << endl;
    }

    // Destructor
    ~Deep() {
        delete data;
    }
};

int main() {
    Deep obj1(10);
    Deep obj2 = obj1;   // Deep copy

    *obj2.data = 20;    // Modify obj2

    cout << "Obj1 data: ";
    obj1.show();        // Unchanged
    cout << "Obj2 data: ";
    obj2.show();

    return 0;
}
