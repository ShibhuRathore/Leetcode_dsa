class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];

        // Build prefix sum
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int sum = prefix[j] - (i > 0 ? prefix[i - 1] : 0);
                if (sum == k) count++;
            }
        }

        return count;
    }
};
