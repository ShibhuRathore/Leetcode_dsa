class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      int i=0;
      int j=k-1;
      int sum=0;
      int maxsum=INT_MIN;
      for(int y=0;y<=j;y++){
        sum+=nums[y];
      }
      maxsum=sum;
      while(j+1<nums.size()){
        j++;
        if(j<nums.size()){
              sum+=nums[j];
        }
        sum-=nums[i];
        maxsum=max(maxsum,sum);
        i++;
      }
      return maxsum/(double) k;
    }
};