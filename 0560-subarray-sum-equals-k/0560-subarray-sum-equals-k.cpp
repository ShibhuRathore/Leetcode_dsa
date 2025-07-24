// prefix sum nikalo
//map mei prefixsum ki frequencies store karo but initially alag loop me beforehand mat karna usese future wale prefixsum ki frequencies bhi stoer ho jayengi 
// diagram yaad karo prefix, pefix-k,k wala 
// fir solve kardo


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
     vector<int>prefix(n,0);
     prefix[0]=nums[0];
     unordered_map<int,int>mp;
     mp[0]=1;
     for(int i=1;i<nums.size();i++){
        prefix[i]=prefix[i-1]+nums[i];
     }
    
     int count=0;
     int j=0;
     while(j<prefix.size()){
        int sum=prefix[j]-k;
        if(mp.find(sum)!=mp.end()){
            count+=mp[sum];
        }
        mp[prefix[j]]++;
        j++;
     }

return count;

    }
};
