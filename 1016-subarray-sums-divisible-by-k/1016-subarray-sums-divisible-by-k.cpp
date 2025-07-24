class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
     int n=nums.size();
     vector<int>prefix(n,0);
     prefix[0]=nums[0];
     for(int i=1;i<nums.size();i++){
        prefix[i]=nums[i]+prefix[i-1];
     }
     unordered_map<int,int>mp;
     mp[0]=1;
     int count=0;
     int j=0;
     while(j<nums.size()){
        int val=prefix[j]%k;
        if(val<0){
            val+=k;
        }
        if(mp.find(val)!=mp.end()){
            count+=mp[val];
        }
        mp[val]++;
        j++;
     }
     return count;
    }
};