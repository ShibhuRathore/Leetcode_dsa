class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
     int maxsum=INT_MIN;
     int minsum=INT_MAX;
     int total=0;
     int currmax=0;
     int currmin=0;
     for(int i=0;i<nums.size();i++){
        total+=nums[i];
        currmax+=nums[i];
        maxsum=max(maxsum,currmax);
        if(currmax<0){currmax=0;}
        currmin+=nums[i];
        minsum=min(minsum,currmin);
        if(currmin>0){currmin=0;}
     }
     if(maxsum<0)return maxsum;
     return max(maxsum,total-minsum);
    }
};