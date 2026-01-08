class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
     int sum=accumulate(nums.begin(),nums.end(),0);
     if(sum<target)return 0;
     int minlen=INT_MAX;
     int i=0;
     int n=nums.size();
     int currsum=0;
     int currlen=0;
     for(int j=0;j<n;j++){
         currsum+=nums[j];
       while(i<=j&&currsum>=target){
          minlen=min(minlen,j-i+1);
          currsum-=nums[i];
          i++;
          
       }
     }
     return minlen;
    }
};