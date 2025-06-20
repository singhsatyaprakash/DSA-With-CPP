#include <iostream>
#include <vector>
using namespace std;

// Function to find the nth ugly number
int nthUglyNumber(int n) {
    vector<int> ugly(n);
    ugly[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    int next2 = 2, next3 = 3, next5 = 5;

    for(int i = 1; i < n; i++) {
        int nextUgly = min(next2, min(next3, next5));
        ugly[i] = nextUgly;

        if(nextUgly == next2) {
            i2++;
            next2 = ugly[i2] * 2;
        }
        if(nextUgly == next3) {
            i3++;
            next3 = ugly[i3] * 3;
        }
        if(nextUgly == next5) {
            i5++;
            next5 = ugly[i5] * 5;
        }
    }
    return ugly[n-1];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "The " << n << "th ugly number is: " << nthUglyNumber(n) << endl;
    return 0;
}