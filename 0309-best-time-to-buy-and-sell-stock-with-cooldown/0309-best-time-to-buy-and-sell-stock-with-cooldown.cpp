class Solution {
public:
    int solve(vector<int>& prices, int index, int holding, vector<vector<int>>& dp) {
        if (index >= prices.size()) {
            return 0;
        }
        if (dp[index][holding] != -1) return dp[index][holding];

        int maxi = solve(prices, index + 1, holding, dp); // Skip this day

        if (holding) {
            // Sell stock and cooldown
            maxi = max(maxi, prices[index] + solve(prices, index + 2, 0, dp));
        } else {
            // Buy stock
            maxi = max(maxi, -prices[index] + solve(prices, index + 1, 1, dp));
        }

        return dp[index][holding] = maxi;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, 0, dp);
    }
};