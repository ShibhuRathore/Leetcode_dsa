class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto &num:arr){
            mp[num]++;
        }
        int maxkey=INT_MIN;
        for(auto &[key,val]:mp){
            if(key==val){
              maxkey=max(maxkey,key)  ;
            }
        }
        return maxkey!=INT_MIN?maxkey:-1;
    }
};