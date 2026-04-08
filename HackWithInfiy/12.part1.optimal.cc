#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void build(int node, int l, int r, vector<int>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return max(query(2 * node, l, mid, ql, qr),
                   query(2 * node + 1, mid + 1, r, ql, qr));
    }

public:
    SegmentTree(vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    int getMax(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    vector<int> bonus(n);
    for (int i = 0; i < n; i++) cin >> bonus[i];

    SegmentTree st(bonus);

    // Precompute divisors of every number up to mx
    vector<vector<int>> divisors(mx + 1);
    for (int d = 1; d <= mx; d++) {
        for (int multiple = d; multiple <= mx; multiple += d) {
            divisors[multiple].push_back(d);
        }
    }

    vector<int> last(mx + 1, -1);
    long long ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (last[arr[i]] != -1) {
            int r = last[arr[i]];
            int maxi = st.getMax(i, r);
            ans += maxi;
        }

        for (int d : divisors[arr[i]]) {
            last[d] = i;
        }
    }

    cout << ans << endl;
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// class SegmentTree{
//     int n;
//     vector<int>tree;
//     void buildTree(int node,int start,int end,vector<int>&arr){
//         if(start==end){
//             tree[node]=arr[start];
//             return;
//         }
//         int mid=(start+end)/2;
//         buildTree(2*node+1,start,mid,arr);
//         buildTree(2*node+2,mid+1,end,arr);
//         tree[node]=max(tree[2*node+1],tree[2*node+2]);
//     }
//     int maxhelper(int node ,int start,int end,int l,int r){
//         if(r<start || end<l){
//             return 0;//out of range
//         }
//         if(l<=start && end<=r){
//             return tree[node];
//         }
//         int mid=(start+end)/2;
//         int leftMax=maxhelper(2*node+1,start,mid,l,r);
//         int rightMax=maxhelper(2*node+2,mid+1,end,l,r);
//         return max(leftMax,rightMax);
//     }
// public:
//     SegmentTree(vector<int>&arr){
//         n=arr.size();
//         tree.resize(4*n, 0);
//         buildTree(0,0,n-1,arr);//nodd,start,end,array...
//     }
//     int getMax(int l,int r){
//         return maxhelper(0,0,n-1,l,r);
//     }
// };
// vector<int>getDivisors(int n){
//     vector<int>div;
//     for(int i=1;i*i<=n;i++){
//         if(n%i==0){
//             div.push_back(i);
//             if(i!=n/i)div.push_back(n/i);
//         }
//     }
//     return div;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     vector<int>bonus(n);
//     for(int i=0;i<n;i++){
//         cin>>bonus[i];
//     }
//     SegmentTree st(bonus);
//     int ans=0;
//     vector<int>div(n/2+1,-1); //first right divisible index...
//     for(int i=n-1;i>=0;i--){

//         if(div[arr[i]]!=-1){
//             int r=div[arr[i]];
//             ans+=st.getMax(i,r);
//         }
        
//         vector<int>div2=getDivisors(arr[i]);
//         for(int j=0; j<div2.size(); j++) {
//             div[div2[j]]=i;
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// const int MAXA = 100005;

// vector<int> getDivisors(int x) {
//     vector<int> divisors;
//     for (int d = 1; d * d <= x; ++d) {
//         if (x % d == 0) {
//             divisors.push_back(d);
//             if (x / d != d) divisors.push_back(x / d);
//         }
//     }
//     return divisors;
// }

// struct SegmentTree {
//     int N;
//     vector<int> tree;

//     SegmentTree(const vector<int>& bonus) {
//         N = bonus.size();
//         tree.resize(4 * N);
//         build(1, 0, N - 1, bonus);
//     }

//     void build(int node, int l, int r, const vector<int>& bonus) {
//         if (l == r) {
//             tree[node] = bonus[l];
//             return;
//         }
//         int mid = (l + r) / 2;
//         build(2 * node, l, mid, bonus);
//         build(2 * node + 1, mid + 1, r, bonus);
//         tree[node] = max(tree[2 * node], tree[2 * node + 1]);
//     }

//     int query(int node, int l, int r, int ql, int qr) {
//         if (qr < l || ql > r) return 0;
//         if (ql <= l && r <= qr) return tree[node];
//         int mid = (l + r) / 2;
//         return max(query(2 * node, l, mid, ql, qr),
//                    query(2 * node + 1, mid + 1, r, ql, qr));
//     }

//     int getMax(int l, int r) {
//         return query(1, 0, N - 1, l, r);
//     }
// };

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N;
//     cin >> N;

//     vector<int> A(N), Bonus(N);
//     for (int i = 0; i < N; ++i) cin >> A[i];
//     for (int i = 0; i < N; ++i) cin >> Bonus[i];

//     SegmentTree seg(Bonus);
//     vector<int> last_seen(MAXA, -1);

//     long long totalXP = 0;

//     // Traverse from right to left
//     for (int i = N - 1; i >= 0; --i) {
//         int val = A[i];
//         int bestR = N;  // initialize to invalid large index

//         vector<int> divisors = getDivisors(val);
//         // bestR = last_seen[A[i]];
//         int tempR = last_seen[A[i]];
        
//         if (tempR != -1 && A[tempR] % A[i] == 0)
//             bestR = tempR;
        
//         for (int d : divisors) {
//             last_seen[d] = i;
//         }

//         if (bestR < N) {
//             totalXP += seg.getMax(i, bestR);
//         }
//     }

//     cout << totalXP << "\n";
//     return 0;
// }