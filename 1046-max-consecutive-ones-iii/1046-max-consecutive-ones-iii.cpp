class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        int maxlen=0;
        while (j < n) {
            if (nums[j] == 0) {
                k--;  // flip 0 to 1
            }

            while (k < 0) {  // too many 0s, shrink window
                if (nums[i] == 0) {
                    k++;  // undo a flip
                }
                i++;
            }
            maxlen=max(j-i+1,maxlen);
            j++;
        }

        return maxlen;  // final valid window size
    }
};
