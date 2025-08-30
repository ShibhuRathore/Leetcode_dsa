class Solution {
public:
 
    int solve(int n, vector<int>&squares,vector<vector<int>>&dp){
        int m=squares.size();
        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        }
        for(int j=1;j<=n;j++){
            dp[0][j]=INT_MAX-1;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(squares[i-1]<=j){
                    dp[i][j]=min(1+dp[i][j-squares[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
    int numSquares(int n) {
        vector<int>squares;
        for(int i=1;i*i<=n;i++){
            squares.push_back(i*i);
        }
        vector<vector<int>>dp(squares.size()+1,vector<int>(n+1,0));
        int ans= solve(n,squares,dp);
        return (ans>=INT_MAX)?-1:ans;
    }
};