class Solution {
public:
    int subset_sum(vector<int>&nums,int s1_sum,vector<vector<int>>&dp){
        int n=nums.size();
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int j=1;j<=s1_sum;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=s1_sum;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
                else if(nums[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][s1_sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum<abs(target))return 0;
        int total=sum+target;
        if(total%2!=0)return 0;
        int s1_sum=total/2;
        vector<vector<int>>dp(n+1,vector<int>(s1_sum+1,0));
        return subset_sum(nums,s1_sum,dp);
    }
};