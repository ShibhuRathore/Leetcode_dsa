class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int it=0;
      int ter=0;
      int n=nums.size();
    while(it<n){
        if(nums[it]!=val){
            nums[ter]=nums[it];
            ter++;
        }
     it++;
      }
        
      
      return ter;
    }
};