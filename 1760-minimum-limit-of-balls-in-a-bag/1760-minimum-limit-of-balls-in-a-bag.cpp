class Solution {
public:
bool ispossible(vector<int>&nums,int mid,int maxOperations){
    long long operationsUsed = 0; // Use long long for safety
        
        for (int balls : nums) {
            // How many times do we need to split this bag 
            // to make every piece <= mid?
            operationsUsed += (balls - 1) / mid;
            
            if (operationsUsed > maxOperations) return false;
        }
        
        return true;
}
    int minimumSize(vector<int>& nums, int maxOperations) {
        int s=1;
        int e=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(nums,mid,maxOperations)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};