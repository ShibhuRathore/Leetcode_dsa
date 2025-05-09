class Solution {
public:
    int numDecodings(string s) {
        if (s[0]=='0') return 0;
        int n=s.size();
        int dp[n+1];
        dp[0]=1; dp[1]=1;

        for (int i=1;i<n;i++){
            dp[i+1]=0;
            if (s[i]!='0'){
                dp[i+1]+=dp[i];
            }
            if (s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6')){
                dp[i+1]+=dp[i-1];
            }
        }
        return dp[n];
    }
};