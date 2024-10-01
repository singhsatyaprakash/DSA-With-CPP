#include <iostream>

class Example {
private:
    int value;

public:
    // Constructor
    Example(int val = 0) : value(val) {}

    // Binary arithmetic operator: +
    Example operator+(const Example& obj) {
        return Example(this->value + obj.value);
    }

    // Unary arithmetic operator: ++ (prefix)
    Example& operator++() {
        ++value;
        return *this;
    }

    // Unary arithmetic operator: -- (prefix)
    Example& operator--() {
        --value;
        return *this;
    }

    // Assignment operator: =
    Example& operator=(const Example& obj) {
        value = obj.value;
        return *this;
    }

    // Compound assignment operator: +=
    Example& operator+=(const Example& obj) {
        value += obj.value;
        return *this;
    }

    // Bitwise operator: &
    Example operator&(const Example& obj) {
        return Example(this->value & obj.value);
    }

    // Dereference operator: -> (returns pointer to a data member)
    Example* operator->() {
        return this;
    }

    // Dynamic memory allocation operator: new
    void* operator new(size_t size) {
        std::cout << "Custom new operator" << std::endl;
        return ::operator new(size);
    }

    // Dynamic memory deallocation operator: delete
    void operator delete(void* ptr) {
        std::cout << "Custom delete operator" << std::endl;
        ::operator delete(ptr);
    }

    // Subscript operator: []
    int& operator[](int index) {
        static int arr[10]; // For demonstration, a static array
        return arr[index];
    }

    // Function call operator: ()
    void operator()(int num) {
        std::cout << "Called with: " << num << std::endl;
    }

    // Logical operator: &&
    bool operator&&(const Example& obj) {
        return (this->value && obj.value);
    }

    // Relational operator: <
    bool operator<(const Example& obj) {
        return this->value < obj.value;
    }

    // Relational operator: ==
    bool operator==(const Example& obj) {
        return this->value == obj.value;
    }

    // Output for demonstration
    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    Example obj1(5), obj2(10);

    // Binary Arithmetic +
    Example result = obj1 + obj2;
    result.display();

    // Unary Arithmetic ++ (prefix)
    ++obj1;
    obj1.display();

    // Unary Arithmetic -- (prefix)
    --obj2;
    obj2.display();

    // Assignment =
    obj1 = obj2;
    obj1.display();

    // Compound Assignment +=
    obj1 += obj2;
    obj1.display();

    // Bitwise &
    result = obj1 & obj2;
    result.display();

    // Dereference ->
    Example* ptr = &obj1;
    ptr->display();

    // Dynamic memory allocation and deallocation
    Example* obj = new Example(20);
    obj->display();
    delete obj;

    // Subscript []
    obj1[2] = 100;
    std::cout << "Subscript result: " << obj1[2] << std::endl;

    // Function call ()
    obj1(15);

    // Logical &&
    std::cout << "Logical AND: " << (obj1 && obj2) << std::endl;

    // Relational <
    std::cout << "Relational < : " << (obj1 < obj2) << std::endl;

    // Relational ==
    std::cout << "Relational == : " << (obj1 == obj2) << std::endl;

    return 0;
}
