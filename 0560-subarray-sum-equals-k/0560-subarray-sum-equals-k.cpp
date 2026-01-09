// prefix sum nikalo
//map mei prefixsum ki frequencies store karo but initially alag loop me beforehand mat karna usese future wale prefixsum ki frequencies bhi stoer ho jayengi 
// diagram yaad karo prefix, pefix-k,k wala 
// fir solve kardo


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     int n=nums.size();
      vector<int>prefix(n);
      prefix[0]=nums[0];
      unordered_map<int,int>mp;
      mp[0]=1;
      int count=0;
      for(int i=1;i<nums.size();i++){
        prefix[i]=prefix[i-1]+nums[i];
      }
      for(int i=0;i<n;i++){
        int target=prefix[i]-k;
        if(mp.find(target)!=mp.end())count+=mp[target];
        mp[prefix[i]]++;
      }
      return count;
    }
};
