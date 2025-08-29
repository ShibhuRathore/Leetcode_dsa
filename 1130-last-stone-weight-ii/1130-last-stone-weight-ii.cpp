class Solution {
public:
    void Knapsack(vector<int>&stones,int sum,vector<vector<bool>>&dp,vector<int>&arr){
        int n=stones.size();
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int j=1;j<=sum;j++){
            dp[0][j]=false;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(stones[i-1]<=j){
                    dp[i][j]=dp[i-1][j-stones[i-1]]||dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        for(int j=0;j<=sum;j++){
            if(dp[n][j]==true){
              arr.push_back(j);
            }
        }
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        int n=stones.size();
        for(auto &ele:stones){
            sum+=ele;
        }
        vector<int>arr;
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        Knapsack(stones,sum/2,dp,arr);
        int ans=INT_MAX;
        for(int i=0;i<arr.size();i++){
             ans=min(ans,sum-2*arr[i]);
        }
    return ans;
    }
};