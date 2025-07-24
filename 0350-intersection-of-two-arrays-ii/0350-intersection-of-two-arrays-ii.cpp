class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int>mp;
       vector<int>ans;
       for(auto &ele:nums1){
        mp[ele]++;
       }
       for(auto &num:nums2){
        if(mp.find(num)!=mp.end()){
            mp[num]--;
            ans.push_back(num);
            if(mp[num]==0){
                mp.erase(num);
            }
        }
       }
       return ans;
    }
};