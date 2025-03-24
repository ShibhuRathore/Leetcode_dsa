class Solution {
public:
    int unique(vector<vector<int>> &obstacleGrid,vector<vector<int>> &dp,int i,int j)
    {
        if( i< 0 || j<0 || i>=obstacleGrid.size() || j>=obstacleGrid[0].size() || obstacleGrid[i][j] == 1)
        {
            return 0;
        }
        if(i == (obstacleGrid.size() -1) && j == (obstacleGrid[0].size() -1) && obstacleGrid[i][j] == 0)
        {
            return 1;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        obstacleGrid[i][j]=1;
        dp[i][j]=unique(obstacleGrid,dp,i+1,j)+unique(obstacleGrid,dp,i,j+1);
        obstacleGrid[i][j]=0;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return unique(obstacleGrid,dp,0,0);
    }
};