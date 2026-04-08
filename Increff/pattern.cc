/*Puzzle question: Print the sequence without using a loop
Input: 16
Output: 16 11 6 1 -4 1 6 11 16
*/
#include <bits/stdc++.h>
using namespace std;

void fun(int n, int original, int delta, bool isDec) {
    cout << n << " ";

    // base condition: when we come back to original and not decreasing
    if (n == original && !isDec)
        return;

    if (isDec) {
        if (n - delta <= 0)
            fun(n - delta, original, delta, false); // switch to increasing
        else
            fun(n - delta, original, delta, true);
    } else {
        fun(n + delta, original, delta, false);
    }
}

int main() {
    int n = 16;
    int delta = 5;

    fun(n, n, delta, true);

    return 0;
}