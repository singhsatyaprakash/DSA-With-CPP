#include<iostream>
#include<vector>
using namespace std;
bool targetSumSubset(vector<int>&nums,int sum,int n){
    if(n==0){
        return false;
    }
    if(sum==0){
        return true;
    }
    if(nums[n-1]<=sum){//valid 
        if(targetSumSubset(nums,sum-nums[n-1],n-1)){
            return true;
        }
        else{
            return targetSumSubset(nums,sum,n-1);
        }
    }
    else{//invlaid
        return targetSumSubset(nums,sum,n-1);
    }
}
int subsetSumMemo(vector<int>&nums,int sum,int n,vector<vector<int>>&dp){
    if(n==0){
        return 0;
    }
    if(sum==0){
        return 1;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }

    if(nums[n-1]<=sum){//valid 
        if(subsetSumMemo(nums,sum-nums[n-1],n-1,dp)){
            dp[n][sum]=1;
        }
        else{
            dp[n][sum]= subsetSumMemo(nums,sum,n-1,dp);
        }
    }
    else{//invlaid
        dp[n][sum]=subsetSumMemo(nums,sum,n-1,dp);
    }
    return dp[n][sum];
}
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int sum;
    cout<<"Enter sum:";
    cin>>sum;
    //cout<<targetSumSubset(nums,sum,n);

    
    //Memorization
    // vector<vector<int>>dpm(n+1,vector<int>(sum+1,-1));
    // cout<<subsetSumMemo(nums,sum,n,dpm);

    //Tabulation...
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    //intialization
    for(int i=0;i<n+1;i++){
        dp[i][0]=true;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(nums[i-1]<=j){
                dp[i][j]= dp[i-1][j] || dp[i-1][j-nums[i-1]] ; // select or not select
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum];


}