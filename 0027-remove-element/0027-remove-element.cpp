class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int it=0;
       int ter=0;
       for(int it=0;it<nums.size();it++){
        if(nums[it]!=val){
            nums[ter]=nums[it];
            ter++;
        }
       }
       return ter;
    }
};