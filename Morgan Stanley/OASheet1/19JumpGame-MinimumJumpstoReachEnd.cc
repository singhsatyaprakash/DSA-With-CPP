#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int helper(int i,int n,vector<int>&arr,vector<int>&dp){
        if(i>=n-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MAX;
        for(int j=i+1;j<=i+arr[i];j++){
            int minpath=helper(j,n,arr,dp);
            if(minpath!=INT_MAX){
                ans=min(ans,1+minpath);
            }
        }
        return dp[i]=ans;
    }
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        int ans=helper(0,n,arr,dp);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
        
    }
};


class Solution2 {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0; // no jumps needed from last index
        
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 1; j <= arr[i] && i + j < n; j++) {
                if(dp[i + j] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i + j]);
                }
            }
        }
        
        return dp[0] == INT_MAX ? -1 : dp[0];
    }
};


class Solution3 {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        if(n <= 1) return 0;
        if(arr[0] == 0) return -1;

        int maxReach = arr[0];
        int steps = arr[0];
        int jumps = 1;

        for(int i = 1; i < n; i++) {
            if(i == n - 1) return jumps;

            maxReach = max(maxReach, i + arr[i]);
            steps--;

            if(steps == 0) {
                jumps++;
                
                if(i >= maxReach) return -1;

                steps = maxReach - i;
            }
        }

        return -1;
    }
};