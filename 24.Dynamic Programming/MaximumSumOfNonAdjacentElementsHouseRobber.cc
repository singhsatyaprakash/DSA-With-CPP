#include<iostream>
#include<vector>
using namespace std;
int MaximumSumNonAdjacent(vector<int>&nums,int idx){
    if(idx==0){
        return nums[idx];
    }
    if(idx<0){
        return 0;
    }
    int pick=nums[idx]+MaximumSumNonAdjacent(nums,idx-2);
    int notpick=0+MaximumSumNonAdjacent(nums,idx-1);
    return max(pick,notpick);
}
int maxSumMemo(vector<int>&nums,int idx,vector<int>&dp){
    if(idx==0){
        return nums[idx];
    }
    if(idx<0){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int pick=nums[idx]+MaximumSumNonAdjacent(nums,idx-2);
    int notpick=0+MaximumSumNonAdjacent(nums,idx-1);
    return dp[idx]=max(pick,notpick);
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    //recursion
    cout<<"Recursion:";
    cout<<MaximumSumNonAdjacent(nums,n-1);

    //memorization
    vector<int>dp(n+1,-1);
    cout<<"\nMeemorization:";
    cout<<maxSumMemo(nums,n-1,dp);

    //Tabualtion
    vector<int>dpt(n+1,0);
    dpt[0]=nums[0];

    for(int i=1;i<n+1;i++){

        int pick=nums[i];
        if(i>1) pick+=dpt[i-2];

        int notpick=0+dpt[i-1];

        dpt[i]=max(pick,notpick);
    }
    cout<<"\nTabulation:";
    cout<<dpt[n];

    //space optimization
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1) pick+=prev2;
        int notpick=0+prev;
        int curr=max(pick,notpick);
        prev2=prev;
        prev=curr;
    }
    cout<<"\nSpace otimization:";
    cout<<prev ;

    return 0;

}