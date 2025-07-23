class Solution {
public:
    int totalFruit(vector<int>& nums) {
     int i=0;
     int j=0;
     unordered_map<int,int>mp;
     int maxlen=INT_MIN;
     while(j<nums.size()){
        mp[nums[j]]++;
        if(mp.size()>2){
            while(mp.size()>2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
        }

        maxlen=max(maxlen,j-i+1);
        j++;
     }
     return maxlen;
    }
};