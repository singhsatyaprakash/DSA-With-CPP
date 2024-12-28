#include<iostream>
#include<vector>
using namespace std;
int fibMem(int n,vector<int>&dp){
    if(n==0 ||n==1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=fibMem(n-1,dp)+fibMem(n-2,dp); //overlapping subproblems as well as optimal substructure to aplly DP...
    return dp[n];
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>fib(n+1,-1);
    cout<<"Fibonacci of "<<n<<" is:"<<fibMem(n,fib);
    return 0;
}