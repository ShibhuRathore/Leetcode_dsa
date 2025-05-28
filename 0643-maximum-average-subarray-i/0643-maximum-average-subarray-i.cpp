class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
     int i =0;
     int j=k-1;
     int sum=0;
     int maxsum=INT_MIN;
     for(int i =0;i<=j;i++){
        sum+=nums[i];
     }
     if(nums.size()==1){
        return nums[0];
     }
     maxsum=sum;
     while(j<nums.size()-1){
        sum-=nums[i++];
        j++;
       
        sum+=nums[j];
        
        maxsum=max(maxsum,sum);
     }
     return maxsum/(double) k;
    }
};