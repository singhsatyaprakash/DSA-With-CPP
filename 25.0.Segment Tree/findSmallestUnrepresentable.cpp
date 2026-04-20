/*You are given an array coins of n positive integers, where each element represents the magical value of a coin.
You are also given q queries. Each query provides a range [a, b] (1-based index) asking:
What is the smallest positive integer that cannot be represented as the sum of any subset of the coins in the subarray coins[a...b]?
Your task is to compute and return the answer for each query.*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
    int n;
    vector<vector<int>> tree;

    // Manually merge two sorted vectors
    vector<int> mergeSorted(vector<int>& left,vector<int>& right) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                merged.push_back(left[i++]);
            } else {
                merged.push_back(right[j++]);
            }
        }
        while (i < left.size()) merged.push_back(left[i++]);
        while (j < right.size()) merged.push_back(right[j++]);
        return merged;
    }

public:
    SegmentTree(vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 0, n - 1, 1);//1-index based...
    }

    void build(vector<int>& data, int l, int r, int node) {
        if (l == r) {
            tree[node] = { data[l] }; //each block is storing a array...
            return;
        }
        int mid = (l + r) / 2;
        build(data, l, mid, 2 * node);//left
        build(data, mid + 1, r, 2 * node + 1);//right
        tree[node] = mergeSorted(tree[2 * node], tree[2 * node + 1]); //build each node storing a sorted array mergring children...
    }

    void query(int l, int r, int ql, int qr, int node, vector<int>& result) {
        if (r < ql || l > qr)
            return;
        if (ql <= l && r <= qr) {
            result = mergeSorted(result, tree[node]);
            return;
        }
        int mid = (l + r) / 2;
        query(l, mid, ql, qr, 2 * node, result);
        query(mid + 1, r, ql, qr, 2 * node + 1, result);
    }

    vector<int> getRange(int ql, int qr) {
        vector<int> result; // This will store the merged and sorted coins in the range [ql, qr]
        query(0, n - 1, ql, qr, 1, result);
        return result;
    }
};

// Greedy algorithm to find the smallest non-representable sum
int findSmallestUnrepresentable(vector<int>& arr) {
    int res = 1;
    for (int i = 0; i < arr.size() && arr[i] <= res; ++i) {
        res += arr[i];
    }
    return res;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
        cin >> coins[i];

    SegmentTree seg(coins);

    while (q--) {
        int a, b;
        cin >> a >> b;
        --a; --b;  // Convert to 0-based
        // Get a sorted vector of coins in the range [a, b] using the segment tree
        vector<int> segment = seg.getRange(a, b);
        cout << findSmallestUnrepresentable(segment) << endl;
    }

    return 0;
}
