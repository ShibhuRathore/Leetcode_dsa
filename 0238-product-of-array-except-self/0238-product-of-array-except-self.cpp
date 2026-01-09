class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,1);
        vector<int>prefix_product(n,1);
        vector<int>suffix_product(n,1);
        
        for(int i=1;i<n;i++){
            prefix_product[i]=prefix_product[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suffix_product[i]=suffix_product[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            res[i]=prefix_product[i]*suffix_product[i];
        }
        return res;
    }
};