class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans.push_back(nums[i]);
                
            }
        }
        // edge cases
        if (ans.empty()) {
            return *max_element(nums.begin(), nums.end());
        }
       set<int>st;
       for(auto &num:ans){
        st.insert(num);
       }
       int sum=0;
       for(auto &ele:st){
        sum+=ele;
       }
       return sum;
    }
};