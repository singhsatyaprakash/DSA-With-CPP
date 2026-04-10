#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int helper(int idx, int n, vector<int>& coins, int sum, vector<vector<int>>& dp) {
        
        if(sum == 0) return 0;
        if(idx == n) return 1e9;
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        int take = 1e9;
        if(sum >= coins[idx]) {
            take = 1 + helper(idx, n, coins, sum - coins[idx], dp);
        }
        
        int notTake = helper(idx + 1, n, coins, sum, dp);
        
        return dp[idx][sum] = min(take, notTake);
    }

    int minCoins(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        
        int ans = helper(0, n, coins, sum, dp);
        
        return (ans >= 1e9) ? -1 : ans;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution2 {
public:
    int minCoins(vector<int>& coins, int sum) {
        int n = coins.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        // Base Case:
        // If no coins left .. impossible (except sum = 0)
        for(int j = 1; j <= sum; j++) {
            dp[n][j] = 1e9;
        }
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= sum; j++) {
                
                int take = 1e9;
                if(j >= coins[i]) {
                    take = 1 + dp[i][j - coins[i]]; // same index (unbounded)
                }

                int notTake = dp[i + 1][j];

                dp[i][j] = min(take, notTake);
            }
        }

        int ans = dp[0][sum];
        return (ans >= 1e9) ? -1 : ans;
    }
};