class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int s=0;
       int e=nums.size()-1;
       int mid=s+(e-s)/2;
       int ans=-1;
       while(s<=e){

        if(nums[mid]>=target){ans=mid;e=mid-1;}
        else if(target>nums[mid]){s=mid+1;}
        mid=s+(e-s)/2;
       }
       return ans==-1?nums.size():ans;
    }
};