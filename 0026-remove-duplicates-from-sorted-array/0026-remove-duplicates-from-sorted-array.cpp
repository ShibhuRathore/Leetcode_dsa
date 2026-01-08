class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int i=0;
     int place=0;
     for(int i=1;i<nums.size();i++){
        if(nums[place]!=nums[i]){
            place++;
        nums[place]=nums[i];
        }
     }
     return place+1;
    }
};