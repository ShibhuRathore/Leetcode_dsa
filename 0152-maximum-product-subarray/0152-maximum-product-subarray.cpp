class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int result=nums[0];
      int currmax=nums[0];
      int currmin=nums[0];
      for(int i=1;i<nums.size();i++){
        int tempmax=currmax;
        currmax=max({nums[i],nums[i]*currmax,nums[i]*currmin});
        currmin=min({nums[i],nums[i]*tempmax,nums[i]*currmin});
        result=max(currmax,result);
      }     
      return result;
    }
};