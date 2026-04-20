#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    int n;
    vector<int> bit; // 1-based indexing

public:
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // update index i by adding value
    void update(int i, int val) {
        while (i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }

    // get prefix sum from 1 to i
    int sum(int i) {
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= (i & -i);
        }
        return res;
    }

    // range sum l to r
    int rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    FenwickTree ft(10); // size = 10

    ft.update(1, 5);
    ft.update(3, 7);
    ft.update(5, 2);

    cout << ft.sum(5) << endl;        // prefix sum [1..5]
    cout << ft.rangeSum(3, 5) << endl; // sum [3..5]

    return 0;
}