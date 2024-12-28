#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw(); // Pure virtual function
    virtual ~Shape() {}     // Virtual destructor for proper cleanup
};

class Rectangle : public Shape {
public:
    void draw()  {
        cout << "Drawing rectangle..." << endl;
    }
};

class Circle : public Shape {
public:
    void draw()  {
        cout << "Drawing circle..." << endl;
    }
};

int main() {
    Shape* s;            // Base class pointer
    Rectangle rec;       // Rectangle object
    Circle cir;          // Circle object

    s = &rec;            // Pointing to Rectangle
    s->draw();           // Calls Rectangle's draw()

    s = &cir;            // Pointing to Circle
    s->draw();           // Calls Circle's draw()

    return 0;
}
