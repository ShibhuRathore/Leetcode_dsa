class Solution {
public:
    int totalFruit(vector<int>& nums) {
      unordered_map<int,int>mp;
      int i=0,j=0;
      int n=nums.size();
      int maxlen=INT_MIN;
      while(j<n){
        mp[nums[j]]++;
        if(mp.size()>2){
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            i++;
        }
        maxlen=max(maxlen,j-i+1);
        j++;

      }

      
      return maxlen;
    }
};