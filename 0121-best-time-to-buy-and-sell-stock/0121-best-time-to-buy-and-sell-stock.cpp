class Solution {
public:
    int maxProfit(vector<int>& nums) {
       int minprice=nums[0];
       int maxprofit=0;
       for(int i=1;i<nums.size();i++){
        minprice=min(nums[i],minprice);
        maxprofit=max(maxprofit,nums[i]-minprice);
       }
       return maxprofit;
    }
};