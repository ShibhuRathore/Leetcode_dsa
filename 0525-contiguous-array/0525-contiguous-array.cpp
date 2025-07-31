class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int maxlength=0;
       unordered_map<int,int>mp;
       int balance=0;
       mp[0]=-1;
       for(int i=0;i<nums.size();i++){
          balance+=nums[i]==1?1:-1;
          if(mp.count(balance)){
            maxlength=max(maxlength,i-mp[balance]);
          }
          else{
            mp[balance]=i;
          }
       }
       return maxlength;
    }
};