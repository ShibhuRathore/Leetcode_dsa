class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int i=0;
      sort(nums.begin(),nums.end());
      int mindiff=INT_MAX;
      int ans=-1;
      while(i<nums.size()){
        int j=i+1;
        int k=nums.size()-1;
        while(j<k){
            int sum=nums[i]+nums[k]+nums[j];
            if(sum>target)k--;
            else if(sum<target)j++;
            else{return sum;}
            int currsum=abs(target-sum);
             if(currsum<mindiff){
                mindiff=currsum;
                ans=sum;
             }


        }
        i++;
      }
      return ans;
    }
};