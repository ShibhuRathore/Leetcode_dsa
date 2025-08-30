class Solution {
public:
  int solve(string &s1,string &s2, int m , int n, vector<vector<int>>&dp){
        for(int i = 0; i <= m; ++i) dp[i][0] = i;   // delete all from s1
        for(int j = 0; j <= n; ++j) dp[0][j] = j;   // insert all into s1
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int minDistance(string s1, string s2) {
          int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        int LCS=solve(s1,s2,m,n,dp);
        return LCS;
    }
};