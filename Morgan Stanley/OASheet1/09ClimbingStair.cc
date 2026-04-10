#include<bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    int helper(int n,vector<int>&memo){
        if(n==0 || n==1){
            return 1;
        }
        if(memo[n]!=-1){
            return memo[n];
        }
        int step1=helper(n-1,memo);
        int step2=0;
        if(n>=2){
            step2=helper(n-2,memo);
        }
        return memo[n]=step1+step2;
    }
    int climbStairs(int n) {
        vector<int>memo(n+1,-1);
        return helper(n,memo);
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};