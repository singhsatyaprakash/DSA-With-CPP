// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int>a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     vector<int>b(n);
//     for(int i=0;i<n;i++){
//         cin>>b[i];
//     }
//     int ans=0;
//     sort(a.rbegin(),a.rend());
//     sort(b.begin(),b.end());
//     string str="";
//     for(int i=0;i<n;i++){
//         str+=string(a[i],'1')+string(b[i],'0');
//     }
//     int m=str.size();
//     int dec=0;
//     int mod=1e9+7;
//     for(int i=0;i<m;i++){
//         dec=dec*2%mod+(str[i]-'0')%mod;
//     }
//     cout<<ans<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    int mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        mx = max(mx, b[i]);
    }

    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());

    vector<long long> pow2(mx + 1);
    pow2[0] = 1;
    for (int i = 1; i <= mx; i++) {
        pow2[i] = (pow2[i - 1] * 2LL) % MOD;
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        // append a[i] ones
        ans = (ans * pow2[a[i]] % MOD + (pow2[a[i]] - 1 + MOD) % MOD) % MOD;

        // append b[i] zeros
        ans = (ans * pow2[b[i]]) % MOD;
    }

    cout << ans << '\n';
    return 0;
}