class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
    int m=s1.size();
    int n=s2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+s1[i-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
     int wt_s1=0;
     int wt_s2=0;
     for(auto &wt:s1)wt_s1+=(int)wt;
     for(auto &wt:s2)wt_s2+=(int)wt;
     return wt_s1+wt_s2-2*dp[m][n];

    }
};
