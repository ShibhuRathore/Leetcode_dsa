class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(n,1);
        vector<int>prev_idx(n,-1);
        int LIS=1;
        int LIS_idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        prev_idx[i]=j;
                    }
                }
            }
            if(dp[i]>LIS){
                LIS=dp[i];
                LIS_idx=i;
            }
        }
        vector<int>ans;
        while(LIS_idx!=-1){
            ans.push_back(nums[LIS_idx]);
            LIS_idx=prev_idx[LIS_idx];
        }   
        return ans;
    }

};

