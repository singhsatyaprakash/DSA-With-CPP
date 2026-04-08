#include<bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    int n;
    vector<int>dp;
    int helper(int i,vector<int>&nums){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+helper(i+2,nums);
        int nottake=helper(i+1,nums);
        return dp[i]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,-1);
        return helper(0,nums);
    }
};
class Solution2{
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2, 0); // extra space to avoid bounds check
        
        for(int i = n - 1; i >= 0; i--) {
            int take = nums[i] + dp[i + 2];
            int nottake = dp[i + 1];
            dp[i] = max(take, nottake);
        }
        
        return dp[0];
    }
};