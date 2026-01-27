class Solution {
public:
    int findMaxLength(vector<int>& nums) {
     unordered_map<int,int>mp;
     mp[0]=-1;
     int maxlength=INT_MIN;
     int balance=0;
     for(int i=0;i<nums.size();i++){
         balance+=nums[i]==0?-1:1;
         if(mp.find(balance)!=mp.end()){
            maxlength=max(maxlength,i-mp[balance]);
         }
         else{
            mp[balance]=i;
         }
     }
     return maxlength==INT_MIN?0:maxlength;
    }
};