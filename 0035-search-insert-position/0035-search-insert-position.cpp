class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int temp=-1;
        while(s<=e){
            int mid=floor(s+(e-s)/2);
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                temp=mid;
                e=mid-1;
            }
        }
        if(temp==-1){
            return nums.size();
        }
        return temp;
    }
};