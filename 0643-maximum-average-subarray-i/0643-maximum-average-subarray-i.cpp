class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int i=0;
        int maxsum=sum;
        for(int j=k;j<nums.size();j++){
            sum-=nums[i];
            i++;
            sum+=nums[j];
            maxsum=max(maxsum,sum);
        }
        return (double)maxsum/k;
    }
};