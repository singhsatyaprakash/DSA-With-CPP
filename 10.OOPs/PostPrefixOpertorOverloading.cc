#include <iostream>

class Example {
private:
    int value;

public:
    // Constructor
    Example(int val = 0) : value(val) {}

    // Prefix increment
    Example& operator++() {
        ++value;
        return *this;
    }

    // Postfix increment
    Example operator++(int) {
        Example temp = *this;  // Save current state
        value++;               // Increment
        return temp;           // Return saved state
    }

    // Prefix decrement
    Example& operator--() {
        --value;
        return *this;
    }

    // Postfix decrement
    Example operator--(int) {
        Example temp = *this;  // Save current state
        value--;               // Decrement
        return temp;           // Return saved state
    }

    // Output for demonstration
    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    Example obj(5);

    std::cout << "Initial value: ";
    obj.display();

    // Prefix increment
    ++obj;
    std::cout << "After prefix increment (++obj): ";
    obj.display();

    // Postfix increment
    obj++;
    std::cout << "After postfix increment (obj++): ";
    obj.display();

    // Prefix decrement
    --obj;
    std::cout << "After prefix decrement (--obj): ";
    obj.display();

    // Postfix decrement
    obj--;
    std::cout << "After postfix decrement (obj--): ";
    obj.display();

    return 0;
}
