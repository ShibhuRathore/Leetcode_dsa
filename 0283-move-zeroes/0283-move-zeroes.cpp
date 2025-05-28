class Solution {  
public:  
    void moveZeroes(vector<int>& nums) {  
     int zerotracker=0;
     int nonzero=0;
     int n=nums.size();
     for(nonzero=0;nonzero<n;nonzero++){
        if(nums[nonzero]!=0){
            swap(nums[zerotracker],nums[nonzero]);
            zerotracker++;
        }

     }
       
    }  
};  