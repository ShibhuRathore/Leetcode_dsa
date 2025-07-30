class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int minRight = n; // Minimum value from the right side
        
        for (int i = n - 1; i >= 2; i--) {
            minRight = min(minRight, nums[i]);
            if (nums[i - 2] > minRight) {
                return false;
            }
        }
        return true;
    }
};
