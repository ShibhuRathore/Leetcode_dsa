#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to perform the final shifting
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        long long total_shift = 0;

        // Traverse from right to left to calculate suffix sum of shifts
        for (int i = n - 1; i >= 0; --i) {
            total_shift = (total_shift + shifts[i]) % 26;

            // Calculate new character by shifting s[i]
            int original_char_index = s[i] - 'a'; // Convert char to 0-25 index
            int new_char_index = (original_char_index + total_shift) % 26; // Apply shift
            s[i] = 'a' + new_char_index; // Convert back to char
        }

        return s; // Return the final shifted string
    }
};
