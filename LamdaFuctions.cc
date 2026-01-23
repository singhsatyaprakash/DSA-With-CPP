#include <bits/stdc++.h>
using namespace std;

int main() {

    cout << "=====Basic Lambda =====\n";
    // simplest form: no capture, just parameters and return
    auto add = [](int a, int b) {
        return a + b;
    };
    cout << "Sum: " << add(3, 5) << "\n\n";

    // ---------------------------------------------

    cout << "=====Lambda with No Parameters =====\n";
    auto greet = []() {
        cout << "Hello Students! 👋\n";
    };
    greet();
    cout << "\n";

    // ---------------------------------------------

    cout << "===== Capture by Value [=] =====\n";
    int x = 10, y = 20;
    auto printSumValue = [=]() { // captures x and y by value
        cout << "Sum (by value): " << x + y << "\n";
    };
    printSumValue();
    x = 50; // won't affect lambda
    printSumValue();
    cout << "\n";

    // ---------------------------------------------

    cout << "===== Capture by Reference [&] =====\n";
    int a = 5, b = 10;
    auto printSumRef = [&]() { // captures a and b by reference
        cout << "Sum (by reference): " << a + b << "\n";
    };
    printSumRef();
    a = 15; // affects lambda
    printSumRef();
    cout << "\n";

    // ---------------------------------------------

    cout << "=====Capture Specific Variables =====\n";
    int m = 3, n = 7, p = 9;
    auto mixCapture = [m, &n]() {
        cout << "Captured by value (m): " << m << "\n";
        cout << "Captured by reference (n): " << n << "\n";
    };
    mixCapture();
    n = 10;
    mixCapture();
    cout << "\n";

    // ---------------------------------------------

    cout << "=====Lambda with Return Type =====\n";
    auto divide = [](double a, double b) -> double {
        if (b == 0) return 0;
        return a / b;
    };
    cout << "Divide: " << divide(10, 2) << "\n\n";

    // ---------------------------------------------

    cout << "=====Lambda Inside Algorithm =====\n";
    vector<int> v = {1, 5, 2, 4, 3};
    cout << "Before sort: ";
    for (int i : v) cout << i << " ";
    cout << "\n";

    // sort descending using lambda comparator
    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
    });

    cout << "After sort: ";
    for (int i : v) cout << i << " ";
    cout << "\n\n";

    // ---------------------------------------------

    cout << "=====Mutable Lambda (modifies captured by value) =====\n";
    int z = 10;
    auto modify = [=]() mutable {
        z += 5; // allowed because of 'mutable'
        cout << "Inside lambda z: " << z << "\n";
    };
    modify();
    cout << "Outside lambda z: " << z << "\n\n";

    // ---------------------------------------------

    cout << "=====Recursive Lambda (with std::function) =====\n";
    function<int(int)> factorial = [&](int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    };
    cout << "Factorial(5): " << factorial(5) << "\n\n";

    // ---------------------------------------------

    cout << "=====Generic Lambda (C++14 and above) =====\n";
    auto multiply = [](auto a, auto b) {
        return a * b;
    };
    cout << "multiply(3, 4): " << multiply(3, 4) << "\n";
    cout << "multiply(2.5, 4.2): " << multiply(2.5, 4.2) << "\n";

    return 0;
}