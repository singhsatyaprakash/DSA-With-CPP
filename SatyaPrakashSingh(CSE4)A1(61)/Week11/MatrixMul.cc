#include<iostream>
#include<vector>
using namespace std;
int MCM(vector<int>&arr,int i,int j,vector<vector<int>>&dp){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int temp=MCM(arr,i,k,dp)+MCM(arr,k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
        if(temp<ans){
            ans=temp;
        }
    }
    return dp[i][j]=ans;
}
int main(){
    int n;
    cout<<"Enter no. of sequences:";
    cin>>n;
    vector<int>arr(n+1);
    cout<<"Enter first row and col size..other enter only column:"<<endl;
    for(int i=0;i<n+1;i++){
        cin>>arr[i];
    }
    vector<vector<int>>dp(1001,vector<int>(1001,-1));
    int cost=MCM(arr,1,arr.size()-1,dp);
    cout<<"Cost of Computation:"<<cost;
    return 0;
}