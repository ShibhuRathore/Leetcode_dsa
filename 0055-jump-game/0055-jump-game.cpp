class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0; // This keeps track of the farthest index we can reach so far

        for(int i = 0; i < n; ++i) {
            if(i > maxReach) {
                // If we reach a point that is beyond our max reach, we are stuck
                return false;
            }

            // Update the maxReach if the current index allows us to go farther
            maxReach = max(maxReach, i + nums[i]);

            // If at any point maxReach touches or exceeds the last index, return true
            if(maxReach >= n - 1) {
                return true;
            }
        }

        // After full iteration, if we never reached the last index
        return true;
    }
};