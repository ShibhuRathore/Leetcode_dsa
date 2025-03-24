
class Solution {
public:
    int rec(int r, int c, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (r == m && c == n) return grid[r][c];
        if (dp[r][c] != -1) return dp[r][c];

        int right = INT_MAX, down = INT_MAX;
        if (c + 1 <= n) right = rec(r, c + 1, m, n, grid, dp);
        if (r + 1 <= m) down = rec(r + 1, c, m, n, grid, dp);

        return dp[r][c] = grid[r][c] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return rec(0, 0, m - 1, n - 1, grid, dp);
    }
};