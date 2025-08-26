class Solution {
public:
int LCS(string &s1, string &s2, int m , int n,vector<vector<int>>&dp){
       if (m == 0 || n == 0) return 0; 
       if(dp[m][n]!=-1)return dp[m][n];
    if(s1[m-1]==s2[n-1]){
        return dp[m][n]= 1+LCS(s1,s2,m-1,n-1,dp);
    }
    else{
        return dp[m][n]=max(LCS(s1,s2,m-1,n,dp),LCS(s1,s2,m,n-1,dp));
    }
    
}
int LCS_tab(string &s1, string &s2, int m , int n,vector<vector<int>>&dp){
 for(int i=0;i<=m;i++){
    dp[i][0]=0;
 }
 for(int j=0;j<=n;j++){
    dp[0][j]=0;
 }
 for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(s1[i-1]==s2[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
        }
        else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

 }
 return dp[m][n];
}
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));// for memoization
        vector<vector<int>>dp(m+1,vector<int>(n+1,0)); // for tabulation

        // return LCS(text1,text2,m,n,dp);
        return LCS_tab(text1,text2,m,n,dp);

    }
};