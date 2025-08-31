class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int LCS=1;
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                   if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                   }
                   else if(dp[j]+1==dp[i]){
                    cnt[i]+=cnt[j];
                   }
                   if(dp[i]>LCS){
                    LCS=dp[i];
                   }
                }
            }
        }
        int total = 0;
        for (int i = 0; i < n; i++) if (dp[i] == LCS) total += cnt[i];
        return total;
    }
};