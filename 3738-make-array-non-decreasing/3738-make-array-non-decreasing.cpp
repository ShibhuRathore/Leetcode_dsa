class Solution {
public:
      int maximumPossibleSize(vector<int>& nums) {
        int res = 0, pre = 0;
        for (int a: nums) {
            if (pre <= a) {
                pre = a;
                res++;
            }
        }
        return res;
    }
};