class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int sum=0;
      unordered_map<int,int> mp;
      for(auto &num1:nums1){
        for(auto &num2:nums2){
            sum=num1+num2;
            mp[sum]++;
        }
      }  
      int count=0;
      int target=0;
      for(auto &num3:nums3){
        for(auto &num4:nums4){
            target=-(num3+num4);
            if(mp.count(target)){
                count+=mp[target];
            }
        }
      }
      return count;
    }
};