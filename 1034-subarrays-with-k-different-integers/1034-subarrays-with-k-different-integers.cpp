class Solution {
public:
int atmostk(vector<int>&nums, int k){
    int left=0;
        int count=0;
        unordered_map<int,int> mp;
        int n=nums.size();
        int right=0;
        while(right<n){
            mp[nums[right]]++;
            while(mp.size()>k){
                 mp[nums[left]]--;
                 if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                 }
                 left++;
            }
           right++;
           count+=right-left+1;
        }
        return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
   return   atmostk(nums,k)-atmostk(nums,k-1);
    }
};