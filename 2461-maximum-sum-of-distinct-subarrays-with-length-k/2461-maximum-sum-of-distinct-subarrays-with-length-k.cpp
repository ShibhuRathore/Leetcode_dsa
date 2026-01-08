class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxsum=0;
         unordered_map<int,int>freq;
         int i=0;
         int n=nums.size();
         long long currsum=0;
         for(int i=0;i<n;i++){
           currsum+=nums[i];
           freq[nums[i]]++;
           if(i>=k){
            currsum-=nums[i-k];
            freq[nums[i-k]]--;
            if(freq[nums[i-k]]==0){
                freq.erase(nums[i-k]);
            }
           }
            if(i>=k-1&&freq.size()==k){
                if(maxsum<currsum)maxsum=currsum;
            }
         }
         return maxsum;
    }
};