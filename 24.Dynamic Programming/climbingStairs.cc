#include<iostream>
#include<vector>
using namespace std;
//recursion
int countRec(int n){
    if(n==1 ||n==2){
        return n;
    }
    return countRec(n-1)+countRec(n-2);
}
//DP with memorization...
int countWaysMemo(int n,vector<int>&dp){
    if(n==1 ||n==2){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=countWaysMemo(n-1,dp)+countWaysMemo(n-2,dp);
    return dp[n];
}
int countWaysTab(int n){
    vector<int>dp(n+1,0);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;
    cout<<"Enter nth stair:";
    cin>>n;
    //by recursion total ways...
    cout<<countRec(n)<<endl;
    //memoriization
    vector<int>dp(n+1,-1);
    cout<<countWaysMemo(n,dp)<<endl;
    //tabulation
    cout<<countWaysTab(n);
    return 0;
}
