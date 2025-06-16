class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
      vector<int> prefix(n);
      vector<int>suffix(n);
      prefix[0]=nums[0];
      suffix[n-1]=nums[n-1];
      for(int i=1;i<n;i++){
        prefix[i]=min(prefix[i-1],nums[i]);
      }
      for(int j=n-2;j>=0;j--){
        suffix[j]=max(suffix[j+1],nums[j]);
      }
      int res=0;
      for(int i=0;i<n;i++){
        res=max(res,suffix[i]-prefix[i]);
      }
      if(res==0) return -1;
      return res;
    }
};