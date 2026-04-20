#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;

    void buildTree(int node, int start, int end, vector<int>& nums) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(2 * node + 1, start, mid, nums);
        buildTree(2 * node + 2, mid + 1, end, nums);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // 🔹 Range update (add val)
    void updateRange(int node, int start, int end, int l, int r, int val) {
        if (start > r || end < l) return; // no overlap

        if (start == end) {
            tree[node] += val;
            return;
        }

        int mid = (start + end) / 2;
        updateRange(2 * node + 1, start, mid, l, r, val);
        updateRange(2 * node + 2, mid + 1, end, l, r, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // 🔹 Point update (set index)
    void updateIndex(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            updateIndex(2 * node + 1, start, mid, idx, val);
        else
            updateIndex(2 * node + 2, mid + 1, end, idx, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // 🔹 Query sum
    int query(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return 0; // no overlap

        if (l <= start && end <= r) return tree[node]; // complete overlap

        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, l, r) +
               query(2 * node + 2, mid + 1, end, l, r);
    }

public:
    SegmentTree(int n, vector<int>& nums) {
        this->n = n;
        tree.resize(4 * n, 0);
        buildTree(0, 0, n - 1, nums);
    }

    // 🔹 Range update
    void update(int l, int r, int val) {
        updateRange(0, 0, n - 1, l, r, val);
    }

    // 🔹 Point update
    void updateAtIndex(int idx, int val) {
        updateIndex(0, 0, n - 1, idx, val);
    }

    // 🔹 Range query
    int getSum(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};