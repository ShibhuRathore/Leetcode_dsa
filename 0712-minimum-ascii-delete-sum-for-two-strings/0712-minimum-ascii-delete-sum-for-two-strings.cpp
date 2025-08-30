class Solution {
public:
void store(string &s1, string &s2, int m, int n, vector<vector<int>>&dp, string&st){
    int i=m;
    int j=n;
    while(i>0&&j>0){
        if(s1[i-1]==s2[j-1]&& dp[i][j] == dp[i-1][j-1] + (int)s1[i-1]){
            st.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(st.begin(),st.end());
}
    void solve(string&s1, string &s2, int m, int n, vector<vector<int>>&dp){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=(int)s1[i-1]+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        solve(s1,s2,m,n,dp);
       string st;
        store(s1,s2,m,n,dp,st);
        long long sum=0;
       int i = 0, k = 0;
        while (i < m){
            if (k < (int)st.size() && s1[i] == st[k]) { ++i; ++k; }
            else { sum += (int)s1[i]; ++i; }
        }

        // s2 vs lcs
        int j = 0; k = 0;
        while (j < n){
            if (k < (int)st.size() && s2[j] == st[k]) { ++j; ++k; }
            else { sum += (int)s2[j]; ++j; }
        }

        return (int)sum;
        
    }
};