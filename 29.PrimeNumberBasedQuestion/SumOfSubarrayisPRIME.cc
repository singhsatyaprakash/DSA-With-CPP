#include<bits/stdc++.h>
using namespace std;

// sieve to generate primes
vector<int> getPrimes(int maxSum){
    vector<bool> isPrime(maxSum+1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for(int i=2;i*i<=maxSum;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=maxSum;j+=i){
                isPrime[j] = false;
            }
        }
    }

    for(int i=2;i<=maxSum;i++){
        if(isPrime[i]) primes.push_back(i);
    }

    return primes;
}

int countPrimeSubarrays(vector<int>& arr){
    int n = arr.size();

    int maxSum = accumulate(arr.begin(), arr.end(), 0);

    vector<int> primes = getPrimes(maxSum);

    unordered_map<int,int> freq;
    freq[0] = 1;

    int prefix = 0;
    int count = 0;

    for(int x : arr){
        prefix += x;

        for(int p : primes){
            if(p > prefix) break;

            if(freq.count(prefix - p)){
                count += freq[prefix - p];
            }
        }

        freq[prefix]++;
    }

    return count;
}

int main(){
    vector<int> arr = {1,2,3,4};
    cout << countPrimeSubarrays(arr);
}