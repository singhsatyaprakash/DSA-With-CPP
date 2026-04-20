//2. Range Update + Range Query (RURQ)
#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    int n;
    vector<int> bit1, bit2;

public:
    FenwickTree(int n) {
        this->n = n;
        bit1.assign(n + 1, 0);
        bit2.assign(n + 1, 0);
    }

    void update(vector<int> &bit, int i, int val) {
        while (i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }

    int query(vector<int> &bit, int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }

    // range update [l, r]
    void rangeUpdate(int l, int r, int val) {
        update(bit1, l, val);
        update(bit1, r + 1, -val);

        update(bit2, l, val * (l - 1));
        update(bit2, r + 1, -val * r);
    }

    int prefixSum(int i) {
        return query(bit1, i) * i - query(bit2, i);
    }

    int rangeSum(int l, int r) {
        return prefixSum(r) - prefixSum(l - 1);
    }
};

int main() {
    FenwickTree ft(10);

    ft.rangeUpdate(2, 5, 3);
    ft.rangeUpdate(4, 8, 2);

    cout << ft.rangeSum(2, 5) << endl;
    cout << ft.rangeSum(1, 8) << endl;

    return 0;
}