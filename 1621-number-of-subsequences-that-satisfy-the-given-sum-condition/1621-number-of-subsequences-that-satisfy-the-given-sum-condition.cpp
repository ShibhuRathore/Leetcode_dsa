class Solution {
public:
    int numSubseq(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        const int mod=1e9+7;
        int start=0;
        int end=n-1;
        int count=0;
        vector<int>power(n,1);
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%mod;
        }
        while(start<=end){
            int sum=nums[start]+nums[end];
            if(sum<=k){
                count=(count+power[end-start])%mod;
                start++;
            }
            else{
                end--;
            }
        }
        return count;
    }
};