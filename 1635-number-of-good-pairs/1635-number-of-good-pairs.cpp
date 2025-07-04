class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0;
        unordered_map<int,int>mp;
        for(int x:nums){
            count+=mp[x]++;
        }
        return count;
    }
};