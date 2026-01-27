class Solution {
public:
        int countsubarray(vector<int>&nums,int bound){
            int total=0;
            int currentcount=0;
            for(auto &num:nums){
                if(num<=bound){
                    currentcount++;
                    total+=currentcount;
                }
                else{
                    currentcount=0;
                }
            }
            return total;
        }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return countsubarray(nums,right)-countsubarray(nums,left-1);
    }
};