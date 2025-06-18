class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>res;
        for(int i=0;i<n;i+=3){{
            int minval=nums[i];
            int midval=nums[i+1];
            int maxval=nums[i+2];
            if(maxval-minval>k){
                return {};
            }
         
            res.push_back({minval,midval,maxval});

        }}
        return res;
    }
};