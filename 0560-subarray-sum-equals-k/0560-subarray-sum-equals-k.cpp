class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int n=nums.size();
      vector<int> prefix(n,0);
      prefix[0]=nums[0];
      int count=0;
      for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+nums[i];
      }  
      unordered_map<int,int>mp;
      for(int j=0;j<n;j++){
        int val=prefix[j]-k;
        if(prefix[j]==k){
            count++;
        }
        if(mp.find(val)!=mp.end()){
            count+=mp[val];
        }
        if(mp.find(prefix[j])==mp.end()){
            mp[prefix[j]]=0;
        }
        mp[prefix[j]]++;
      }
      return count;
    }
};
