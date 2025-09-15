class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        int i=0;
        int j=0;
        int count=0;
        int prod=1;
        int n=nums.size();
        while(j<n){
            if(prod<k){
                prod*=nums[j];
            }
            while(prod>=k&&i<=j){
                prod/=nums[i];
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
};