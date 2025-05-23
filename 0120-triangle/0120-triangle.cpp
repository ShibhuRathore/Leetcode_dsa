class Solution {
public:
    // Recursive Approach
    int recur(vector<vector<int>>& triangle, int i, int j){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        int down = triangle[i][j] + recur(triangle, i+1,j);
        int diag = triangle[i][j] + recur(triangle, i+1,j+1);
        return min(diag,down);
    }
    // Memoization Approach
    int solve(vector<vector<int>>& triangle, int i, int j,vector<vector<int>>& dp){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j]!= -1)   return dp[i][j];

        int down = triangle[i][j] + solve(triangle, i+1,j,dp);
        int diag = triangle[i][j] + solve(triangle, i+1,j+1,dp);
        return dp[i][j] = min(diag,down);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(triangle, 0,0,dp);
    }
};