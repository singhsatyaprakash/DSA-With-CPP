#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int size;
    vector<int> tree;

    SegmentTree(int n) {
        size = n;
        tree.assign(4 * n, 0);
    }

    void update(int idx, int value, int node, int start, int end) {
        if (start == end) {
            tree[node] = max(tree[node], value);
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(idx, value, 2 * node + 1, start, mid);
        else
            update(idx, value, 2 * node + 2, mid + 1, end);

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int query(int l, int r, int node, int start, int end) {
        if (r < start || end < l) return 0;

        if (l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;

        return max(
            query(l, r, 2 * node + 1, start, mid),
            query(l, r, 2 * node + 2, mid + 1, end)
        );
    }

    void update(int idx, int value) {
        update(idx, value, 0, 0, size - 1);
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(l, r, 0, 0, size - 1);
    }
};

bool isValid(int k, const vector<int>& p, int m) {
    int n = p.size();
    vector<pair<int, int>> val_index;

    for (int i = 0; i < n; i++) {
        val_index.push_back({p[i], i});
    }

    sort(val_index.begin(), val_index.end());

    SegmentTree st(n);

    for (auto &it : val_index) {
        int val = it.first;
        int idx = it.second;

        int l = max(0, idx - k);
        int r = min(n - 1, idx + k);

        int best = st.query(l, r);
        int curr = best + 1;

        st.update(idx, curr);

        if (curr >= m) return true;
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    int lo = 0, hi = n - 1, ans = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (isValid(mid, p, m)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}