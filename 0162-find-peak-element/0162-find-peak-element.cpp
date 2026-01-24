class Solution {
public:
    int findPeakElement(vector<int>& nums) {
  int n=nums.size();
  int s=0;
  int e=nums.size()-1;
  int ans=-1;
  if(n==1)return 0;
  if(n==2)return nums[1]>nums[0]?1:0;
  if(nums[0]>nums[1])return 0;
  if(nums[n-1]>nums[n-2])return n-1;
  while(s<=e){
    int mid=s+(e-s)/2;
    if(nums[mid]<nums[mid+1]){
        s=mid+1;
    }
    else{
        ans=mid;
        e=mid-1;
    }
  }
  return ans;
    }
};