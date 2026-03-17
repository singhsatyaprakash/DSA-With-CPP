#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    //Time: O(n log log n)...
    vector<bool>isPrime(n+1,true);
    isPrime[0]=false;
    isPrime[1]=false;

    for(int i=2;i*i<=n;i++){
        if(isPrime[i]==true){
            for(int j=2;i*j<n;j++){
                isPrime[i*j]=false;
            }
        }
    }
    int count=0;
    for(int i=2;i<=n;i++){
        if(isPrime[i]==true) count++;
    }
    cout<<"Total Prime numbers upto N:"<<count;
    return 0;
}