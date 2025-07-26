class Solution {
public:
    int totalFruit(vector<int>& nums) {
      unordered_map<int,int>mp;
     int maxlen=INT_MIN;
      int i=0;
      int j=0;
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