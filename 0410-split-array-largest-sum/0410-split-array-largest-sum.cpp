class Solution {
public:

   bool isvalid(vector<int>&nums,int k, int i){
    int currsum=0;
    int split=1;
    for(int &num:nums){
        if(num+currsum<=i){
            currsum+=num;
        }
        else{
            currsum=num;
            split++;
        }
        if (split>k)return false;
    }
    return true;
   }
    int splitArray(vector<int>& nums, int k) {
        int low =*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isvalid(nums,k,mid)) {
                ans=mid;
                high=mid-1;}
            else{
                
                low=mid+1;
            }
        }
        return ans;
    }
};