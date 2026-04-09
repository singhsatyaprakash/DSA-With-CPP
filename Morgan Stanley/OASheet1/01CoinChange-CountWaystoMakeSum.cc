#include<bits/stdc++.h>
using namespace std;
class Solution1 {
  public:
    int helper(int idx,int n,vector<int>&coins,int sum,vector<vector<int>>&dp){
        if(sum==0){
            return 1;
        }
        if(idx==n){
            return 0;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        
        int ans=0;
        if(sum>=coins[idx]){
            ans+=helper(idx,n,coins,sum-coins[idx],dp)+helper(idx+1,n,coins,sum,dp);
        }
        else{
            
            ans+=helper(idx+1,n,coins,sum,dp);
        }
        return dp[idx][sum]=ans;
    }
    int count(vector<int>& coins, int sum) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return helper(0,n,coins,sum,dp);
    }
};


class Solution2 {
public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {//index...
            for (int j = 1; j <= sum; j++) {//sum...

                int take = 0;
                if (j >= coins[i]) {
                    take = dp[i][j - coins[i]];
                }

                int notTake = dp[i + 1][j];

                dp[i][j] = take + notTake;
            }
        }

        return dp[0][sum];
    }
};