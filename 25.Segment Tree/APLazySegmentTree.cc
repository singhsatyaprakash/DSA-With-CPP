#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class SegmentTree {
private:
    int n;
    vector<long long> tree;
    vector<long long> lazy_a, lazy_d;

    // Build
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2*node+1, start, mid);
        build(arr, 2*node+2, mid+1, end);
        tree[node] = (tree[2*node+1] + tree[2*node+2]) % MOD;
    }

    // Apply AP update to node
    void apply(int node, int start, int end, long long a, long long d) {
        int len = end - start + 1;

        long long sum = (len * (2*a % MOD + (len-1)*d % MOD) % MOD * 500000004) % MOD;
        tree[node] = sum;

        lazy_a[node] = a;
        lazy_d[node] = d;
    }

    // Push lazy to children
    void push(int node, int start, int end) {
        if (lazy_a[node] == 0 && lazy_d[node] == 0) return;

        int mid = (start + end) / 2;

        // Left child
        apply(2*node+1, start, mid, lazy_a[node], lazy_d[node]);

        // Right child
        long long new_a = (lazy_a[node] + (mid - start + 1) * lazy_d[node]) % MOD;
        apply(2*node+2, mid+1, end, new_a, lazy_d[node]);

        lazy_a[node] = lazy_d[node] = 0;
    }

    // Update AP
    void update(int node, int start, int end, int l, int r, long long x, long long y) {
        if (start > r || end < l) return;

        if (l <= start && end <= r) {
            long long a = (x + (start - l) * y) % MOD;
            apply(node, start, end, a, y);
            return;
        }

        push(node, start, end);

        int mid = (start + end) / 2;
        update(2*node+1, start, mid, l, r, x, y);
        update(2*node+2, mid+1, end, l, r, x, y);

        tree[node] = (tree[2*node+1] + tree[2*node+2]) % MOD;
    }

    // Query sum
    long long query(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return 0;

        if (l <= start && end <= r) return tree[node];

        push(node, start, end);

        int mid = (start + end) / 2;
        return (query(2*node+1, start, mid, l, r) +
                query(2*node+2, mid+1, end, l, r)) % MOD;
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n);
        lazy_a.resize(4*n, 0);
        lazy_d.resize(4*n, 0);
        build(arr, 0, 0, n-1);
    }

    void updateQuery(int l, int r, int x, int y) {
        update(0, 0, n-1, l, r, x, y);
    }

    long long getSum() {
        return tree[0];
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    SegmentTree st(A);

    int q;
    cin >> q;

    while (q--) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        st.updateQuery(l, r, x, y);
    }

    cout << st.getSum() % MOD << endl;
}