class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum=nums[0];
        int currmax=0;
        int minsum=nums[0];
        int currmin=0;
        int total=0;
        for(int i=0;i<nums.size();i++){
            currmax=max(nums[i],currmax+nums[i]);
            maxsum=max(currmax,maxsum);

            currmin=min(nums[i],currmin+nums[i]);
            minsum=min(currmin,minsum);

            total+=nums[i];
        }
        if(minsum==total){
            return maxsum;
        }
        return max(maxsum,total-minsum);
    }
};