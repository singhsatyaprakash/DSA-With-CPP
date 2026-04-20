// Range Update + Point Query (RUPQ)

#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    int n;
    vector<int> bit;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, int val) {
        while (i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }

    // range update [l, r] by val
    void rangeUpdate(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }
};

int main() {
    FenwickTree ft(10);

    ft.rangeUpdate(2, 5, 3); // add +3 to [2..5]
    ft.rangeUpdate(4, 8, 2); // add +2 to [4..8]

    cout << ft.query(4) << endl; // value at index 4
    cout << ft.query(6) << endl; // value at index 6

    return 0;
}