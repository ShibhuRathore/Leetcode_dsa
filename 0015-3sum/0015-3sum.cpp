class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       int i=0;
       set<vector<int> >st;
       vector<vector<int>> output;
       for(int i=0;i<nums.size();i++){
        int j=i+1;
       int k=nums.size()-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==0){
                st.insert({nums[i],nums[j],nums[k]});
                j++;
                k--;
            }
            if(sum<0){
                j++;
            }
            if(sum>0){
                k--;
            }
        }

       } 
       for(auto triplets:st){
        output.push_back(triplets);
       }
       return output;
    }
};