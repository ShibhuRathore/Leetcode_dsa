class Solution {
public:
    int superEggDrop(int k, int n) {
      vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        int m = 0; // Number of moves
        // Keep increasing moves until we can check at least 'n' floors
        while (dp[k][m] < n) {
            m++;
            for (int eggs = 1; eggs <= k; eggs++) {
                // Transition:
                // 1. dp[eggs - 1][m - 1] → If egg breaks
                // 2. dp[eggs][m - 1]     → If egg survives
                // +1 → current floor tested
                dp[eggs][m] = 1 + dp[eggs - 1][m - 1] + dp[eggs][m - 1];
            }
        }

        // 'm' is the minimum number of moves required to check 'n' floors with 'k' eggs
        return m;
    }
};