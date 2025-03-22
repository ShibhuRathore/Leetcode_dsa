#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rec(int r, int c, int m, int n, vector<vector<int>> &dp) {
        if (r == m && c == n) return 1;
        if (r > m || c > n) return 0;
        if (dp[r][c] != -1) return dp[r][c];
        
        int right = rec(r, c + 1, m, n, dp);
        int down = rec(r + 1, c, m, n, dp);
        
        return dp[r][c] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return rec(0, 0, m - 1, n - 1, dp) % (2 * 1000000000);
    }
};