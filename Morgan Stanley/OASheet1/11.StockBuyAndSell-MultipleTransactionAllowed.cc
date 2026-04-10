#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        
        if(idx == prices.size()) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;

        if(buy) {
            // Option 1: Buy
            int take = -prices[idx] + helper(idx + 1, 0, prices, dp);
            // Option 2: Skip
            int notTake = helper(idx + 1, 1, prices, dp);

            profit = max(take, notTake);
        }
        else {
            // Option 1: Sell
            int take = prices[idx] + helper(idx + 1, 1, prices, dp);
            // Option 2: Skip
            int notTake = helper(idx + 1, 0, prices, dp);

            profit = max(take, notTake);
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return helper(0, 1, prices, dp); // start with buy allowed
    }
};