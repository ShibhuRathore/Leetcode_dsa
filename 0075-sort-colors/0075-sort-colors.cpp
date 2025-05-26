class Solution {
public:
    void sortColors(vector<int>& nums) {
       int zero=0;
       int two=nums.size()-1;
       int it=0;
       while(it<=two){
        if(nums[it]==0){
            swap(nums[it],nums[zero]);
                zero++;
                it++;
        }
       else if(nums[it]==2){
            swap(nums[it],nums[two]);
                two--;
            
        }
        else{
            it++;
        }
       }
    }
};