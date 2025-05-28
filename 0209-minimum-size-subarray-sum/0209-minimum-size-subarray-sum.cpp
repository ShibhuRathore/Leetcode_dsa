class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int i=0;
      int j=0;
      int minlen=INT_MAX;
      int len=0;
      int n=nums.size();
      int sum=nums[0];
      while(j<n){
        if(sum<target){
            j++;
            if(j<n){
                sum+=nums[j];
            }
          
        }  else {
                len=j-i+1;
                minlen=min(len,minlen);
                sum-=nums[i];
                i++;
            }
      }
       return minlen==INT_MAX?0:minlen;
    }
};