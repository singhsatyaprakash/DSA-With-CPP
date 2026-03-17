#include<bits/stdc++.h>
using namespace std;

int main(){
    int L, R;
    cin >> L >> R;

    int n = R;
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    // Sieve
    for(int i = 2; i*i <= n; i++){
        if(isPrime[i]){
            for(int j = i*i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }

    // Prefix sum
    vector<long long> prefix(n+1, 0);
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1];
        if(isPrime[i]) prefix[i] += i;
    }

    // Answer
    long long ans = prefix[R] - (L > 1 ? prefix[L-1] : 0);
    cout << ans;
}