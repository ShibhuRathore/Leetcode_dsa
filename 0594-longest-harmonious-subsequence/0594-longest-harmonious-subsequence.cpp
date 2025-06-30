class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int &num:nums){
            mp[num]++;
        }
      int maxLength = 0;
        for (auto &[num, count] : mp) {
            if (mp.count(num + 1)) {
                maxLength = max(maxLength, count + mp[num + 1]);
            }
        }

        return maxLength;
    }
    
};