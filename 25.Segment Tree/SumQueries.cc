/*You’re given an array A of n integers and q queries.
Each query can be one of the following two types:
• Type 1 Query: (1, l, r) - Replace A[i] with
(i-l+1)*A[l] for each index i, where l <= i <= r.
• Type 2 Query: (2, l, r) - Calculate the sum of the
elements in A from index l to index r.
Find the sum of answers to all type 2 queries. Since
answer can be large, return it modulo 10^9+7.*/
#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
class SegmentTree {
private:
    int n;
    vector<int> tree;
  
    void buildTree(vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(arr, start, mid, 2 * node + 1);
        buildTree(arr, mid + 1, end, 2 * node + 2);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int rangeSum(int qi, int qj, int si, int sj, int node) {//(queryleft,queryright,segmentStart,segmentEnd)
        if (qj < si || sj < qi) return 0; // No overlap...
        if (qi <= si && qj >= sj) return tree[node]; // Complete overlap...
        //partial overlapping...
        int mid = si + (sj - si) / 2;
        return rangeSum(qi, qj, si, mid, 2 * node + 1) +
               rangeSum(qi, qj, mid + 1, sj, 2 * node + 2);
    }

    void updateUtil(int idx, int newVal, int start, int end, int node) {
        if (start == end) {
            tree[node] = newVal;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            updateUtil(idx, newVal, start, mid, 2 * node + 1);
        } else {
            updateUtil(idx, newVal, mid + 1, end, 2 * node + 2);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, n - 1, 0);
    }

    int rangeQuery(int qi, int qj) {
        return rangeSum(qi, qj, 0, n - 1, 0);
    }

    void updateQuery(int idx, int newVal) {
        updateUtil(idx, newVal, 0, n - 1, 0);
    }
};

int main() {
    int n;
    //cout << "Enter size of array:";
    cin >> n;
    vector<int> arr(n);
    //cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int q;
    //cout << "Enter no. of queries:";
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(3));
    //cout << "Enter queries (type left right):\n";
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    SegmentTree st(arr);
    long long totalSum = 0;

    for (int i = 0; i < q; i++) {
        int type = queries[i][0];
        int l = queries[i][1];  
        int r = queries[i][2];

        if (type == 1) {
            int baseVal = arr[l];
            for (int j = l; j <= r; j++) {
                arr[j] = (j - l + 1) * baseVal;
                st.updateQuery(j, arr[j]);//lets update tree now...
            }
        } else if (type == 2) {
            int sum = st.rangeQuery(l, r);
            totalSum = (totalSum + sum) % MOD;
        }
    }

    cout << totalSum << endl;
    return 0;
}
