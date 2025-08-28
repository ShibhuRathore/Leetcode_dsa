class Solution {
public:
    int solve(vector<int>&a,int i, int j, vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            int tempAns=solve(a,i,k-1,dp)+solve(a,k+1,j,dp)+a[i-1] * a[k] * a[j+1];
            maxi=max(maxi,tempAns);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n =nums.size();
          vector<int> a(n + 2, 1);
         for (int i = 1; i <= n; ++i) a[i] = nums[i-1];
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return solve(a,1,n,dp);

    }
};