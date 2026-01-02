class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size()/2;
        unordered_map<int,int>mp;
        for(auto &ele:nums){
            mp[ele]++;
            if(mp[ele]==n)return ele;
        }
       return -1;
    }
};