#include <iostream>
using namespace std;

void nestedFunction() {
    try {
        // Throwing an exception
        throw runtime_error("An error occurred in nestedFunction!");
    } catch (const runtime_error& e) {
        cout << "Caught exception in nestedFunction: " << e.what() << endl;
        // Re-throw the exception
        throw;
    }
}

int main() {
    try {
        nestedFunction();
    } catch (const runtime_error& e) {
        cout << "Caught re-thrown exception in main: " << e.what() << endl;
    }

    return 0;
}
