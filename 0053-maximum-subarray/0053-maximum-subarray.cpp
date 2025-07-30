class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int maxsum=nums[0];
      int currsum=nums[0];
      for(int i=1;i<nums.size();i++){
        // currsum=nums[i]; if by adding new value it has become neagtive
        //currsum=nums[i]+currsum if the value is increaed;
        currsum=max(nums[i],currsum+nums[i]);
        maxsum=max(currsum,maxsum);
      }
      return maxsum;
    }
};