#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9+7;

class SegementTree {
private:
    int n;
    vector<long long> tree;

    // lazyA[node] = first term add for this segment
    // lazyD[node] = common diff add for this segment
    vector<long long> lazyA, lazyD;

    long long sumAP(long long a, long long d, long long len) {
        // sum = len/2 * (2a + (len-1)d)
        long long twoA = (2LL * a) % MOD;
        long long part = (twoA + ((len - 1) % MOD) * d) % MOD;
        long long res = (len % MOD) * part % MOD;

        // divide by 2 using inverse of 2 in MOD
        res = res * ((MOD + 1) / 2) % MOD;
        return res;
    }

    void buildTree(vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start] % MOD;
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(arr, start, mid, 2 * node + 1);
        buildTree(arr, mid + 1, end, 2 * node + 2);
        tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % MOD;
    }

    void push(int node, int start, int end) {
        if (lazyA[node] == 0 && lazyD[node] == 0) return;
        
        long long len = end - start + 1;

        // apply lazy update to this node sum
        tree[node] = (tree[node] + sumAP(lazyA[node], lazyD[node], len)) % MOD;

        if (start != end) {
            int left = 2 * node + 1;
            int right = 2 * node + 2;
            int mid = start + (end - start) / 2;

            long long leftLen = mid - start + 1;

            // left child gets same (A, D)
            lazyA[left] = (lazyA[left] + lazyA[node]) % MOD;
            lazyD[left] = (lazyD[left] + lazyD[node]) % MOD;

            // right child first term shifts by leftLen * D
            long long shiftedA = (lazyA[node] + (leftLen % MOD) * lazyD[node]) % MOD;

            lazyA[right] = (lazyA[right] + shiftedA) % MOD;
            lazyD[right] = (lazyD[right] + lazyD[node]) % MOD;
        }

        lazyA[node] = 0;
        lazyD[node] = 0;
    }

    long long sumUtils(int l, int r, int start, int end, int node) {
        push(node, start, end);

        if (l > end || r < start || l > r) return 0;

        if (l <= start && end <= r) return tree[node];

        int mid = start + (end - start) / 2;
        long long leftSum = sumUtils(l, r, start, mid, 2 * node + 1);
        long long rightSum = sumUtils(l, r, mid + 1, end, 2 * node + 2);

        return (leftSum + rightSum) % MOD;
    }

    void updateHelper(int l, int r, long long a, long long d, int start, int end, int node) {
        push(node, start, end);

        if (l > end || r < start || l > r) return;

        if (l <= start && end <= r) {
            // AP starts at l, but current segment starts at start
            long long shift = start - l;
            long long firstTermHere = (a + (shift % MOD) * d) % MOD;

            lazyA[node] = (lazyA[node] + firstTermHere) % MOD;
            lazyD[node] = (lazyD[node] + d) % MOD;

            push(node, start, end);
            return;
        }

        int mid = start + (end - start) / 2;
        updateHelper(l, r, a, d, start, mid, 2 * node + 1);
        updateHelper(l, r, a, d, mid + 1, end, 2 * node + 2);

        tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % MOD;
    }

public:
    SegementTree(vector<int>& arr) {
        n = (int)arr.size();
        tree.assign(4 * n, 0);
        lazyA.assign(4 * n, 0);
        lazyD.assign(4 * n, 0);
        buildTree(arr, 0, n - 1, 0);
    }

    long long getSumQuery(int l, int r) {
        return sumUtils(l, r, 0, n - 1, 0);
    }

    void updateQuery(int l, int r) {
        // base = current value at index l
        long long base = getSumQuery(l, l);

        // increment AP: 0, base, 2*base, 3*base....
        // so add AP with first term = 0, diff = base
        updateHelper(l, r, 0, base, 0, n - 1, 0);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int q;
    cin >> q;

    SegementTree st(arr);
    long long sum = 0;

    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1) {
            st.updateQuery(l, r);
        } else {
            sum = (sum + st.getSumQuery(l, r)) % MOD;
        }
    }

    cout << sum % MOD << "\n";
    return 0;
}
