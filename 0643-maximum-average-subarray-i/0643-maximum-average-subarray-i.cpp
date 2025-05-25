class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i =0;
        int j=k-1;
        int sum=0;
        for (int i =0;i<=j;i++){
            sum=sum+nums[i];
        }
        j++;
       int maxsum=sum;
     while(j<nums.size()){
            sum=sum-nums[i++];
            sum=sum+nums[j++];
            maxsum=max(maxsum,sum);
        }
       double maxavg=maxsum/(double) k;
       return maxavg;
    }
};