class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();

        unordered_set<int>st;

        int ans=0;
        int i=0,j=0;
        int sum=0;

        while(j<n){
            sum+=nums[j];

            while(st.count(nums[j])){
                st.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            
            st.insert(nums[j]);
            ans=max(ans,sum);
            j++;
        }
        return ans;
    }
};