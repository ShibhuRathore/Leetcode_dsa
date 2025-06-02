class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>result;
        for(auto &num:nums1){
            mp[num]++;
        }
        for(auto &val:nums2){
            if(mp[val]!=0){
                result.push_back(val);
                mp.erase(val);
            }
        }
        return result;
    }
};