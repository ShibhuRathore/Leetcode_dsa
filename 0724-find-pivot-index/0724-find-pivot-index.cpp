class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // calculate prefix sum from the left and right both direction
        int n =nums.size();
        vector<int>leftsum(n,0);
        vector<int>rightsum(n,0);
        leftsum[0]=nums[0];
        rightsum[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
           leftsum[i]=leftsum[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            rightsum[i]=rightsum[i+1]+nums[i];
        }
        for(int i=0;i<n;i++){
            if(leftsum[i]==rightsum[i]){
                return i;
            }
        }
        return -1;
    }
};