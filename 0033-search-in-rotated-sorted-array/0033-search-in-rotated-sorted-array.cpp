class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if (nums[mid] == target)
                return mid;
            // left array is sorted 
            if(nums[s]<=nums[mid]){
                //target is present in the left part
                // extra condition nums[s]<=target islie lagani pad rahi h ki left part< target warna agar extreme left hi bada ho jayega to left part mei target hoga hi nahi
                if(nums[mid]>target && nums[s]<=target){
                    e=mid-1;                }
                else{
                    s=mid+1;
                }
            }
            //right array is sorted
            else{
                // target is present in the right part
               if(nums[mid]<target && nums[e]>=target){
                s=mid+1;
               }
               else{
                e=mid-1;
               }
            }
        }
        return -1;
    }
};