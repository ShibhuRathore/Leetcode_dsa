class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
     int n=nums.size();
     int count=0;
     vector<int>prefix(n,0);
     prefix[0]=nums[0];
     for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+nums[i];
     }
     unordered_map<int,int> mp;
     for(int j=0;j<n;j++){
        int val=prefix[j]%k;
        // making mod positive if it is negative
       if(val<0){
        val+=k;
       }
       if((prefix[j]%k==0)){
        count++;
       }
        if(mp.find(val)!=mp.end()){
            count+=mp[val];
        }
      
        mp[val]++;
     }
     return count;
    }
};