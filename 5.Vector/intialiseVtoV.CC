// C++ program to initialize a vector from
// another vector.
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vect1{ 10, 20, 30 };

    vector<int> vect2(vect1.begin(), vect1.end());

    for (int x : vect2)
        cout << x << " ";

    return 0;
}

/*
#include <iostream>
#include <vector>

// Function that returns a vector
std::vector<int> getVector() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    return vec;
}

int main() {
    // Initialize vector in main by using the vector returned from the function
    std::vector<int> myVector = getVector();

    // Print the vector to verify
    for (int val : myVector) {
        std::cout << val << " ";
    }

    return 0;
}

*/