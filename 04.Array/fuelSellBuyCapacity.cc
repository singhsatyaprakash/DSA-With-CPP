/*
You have an oil tank with a capacity of C litres that
can be bought and sold by N people. The people
are standing in a queue and are served sequentially in
the order of array A.

Some of them want to sell a litre of oil and some of
them want to buy a litre of oil. A[i] = 1 denotes that
the person wants to sell a litre of oil and A[i] = -1
denotes that the person wants to buy a litre of oil.

When a person wants to sell a litre of oil but the
tank is full, they cannot sell it and become upset.
Similarly, when a person wants to buy a litre of
oil but the tank is empty, they cannot buy it and
become upset. Both these cases cause disturbances.

You can minimize the disturbance by filling the tank
initially with a certain X litres of oil.
Find the minimum initial amount of oil X that results
in the least number of disturbances.
*/
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, C;
    cin >> n >> C;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i]; //{1,-1,1,-1,-1} capacity=2

    int prefix = 0;
    int minX = 0, maxX = C;
    for (int i = 0; i < n; i++) {
        prefix += A[i];  //current oil level in the tank...
        minX = max(minX, -prefix);        // To avoid negative level...
        maxX = min(maxX, C - prefix);     // To avoid exceeding capacity...
    }

    if (minX > maxX)
        cout << 0 << endl;  // No valid X can prevent all disturbances
    else
        cout << minX << endl;  // Minimum initial amount to avoid all disturbances

    return 0;
}


