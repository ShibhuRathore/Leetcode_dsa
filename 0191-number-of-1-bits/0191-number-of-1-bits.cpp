class Solution {
public:
    unsigned int count = 0;
    int hammingWeight(unsigned int n) {
        if (n == 0)
            return count;
        if((n & 1) == 1)
            count++;
        
        n = n >> 1;
        return hammingWeight(n);
    }
};