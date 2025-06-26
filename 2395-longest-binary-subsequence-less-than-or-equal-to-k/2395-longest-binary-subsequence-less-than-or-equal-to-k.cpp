class Solution {
public:
int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;        // Final count of characters in the valid subsequence
        int val = 0;          // Current binary value built from the right side
        int bitPos = 0;       // Position of bit (0 for rightmost)

        // Traverse the string from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                // Always include '0' since it doesn't increase the value
                count++;
            } else {
                // For '1', check if adding 2^bitPos keeps value within k
                if (bitPos < 31) {  // Only 32 bits needed as 2^31 > 1e9
                    int add = 1 << bitPos; // 2^bitPos
                    if (val + add <= k) {
                        val += add; // include this bit in total value
                        count++;
                    }
                }
            }
            // Increment bit position in every step
            if (s[i] == '1' || s[i] == '0')
                bitPos++;
        }

        return count;
    }
};