// first fill all the non zero elements and then fill the remaining spaces with all the zeroes


class Solution {  
public:  
    void moveZeroes(vector<int>& nums) {  
        int i=0;
      for(auto &num:nums){
        if(num!=0){
            nums[i]=num;
            i++;
        }
      }
    for(int j=i;j<nums.size();j++){
        nums[j]=0;
    }
    
    }
};  