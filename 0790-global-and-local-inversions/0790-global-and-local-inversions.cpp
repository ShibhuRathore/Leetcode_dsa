class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int minright = nums[n-1]; // Minimum value from the right side
        for(int i=n-1;i>=2;i--){
            minright=min(minright,nums[i]);
            if(minright<nums[i-2])return false;
        }
       return true;
    }
};
