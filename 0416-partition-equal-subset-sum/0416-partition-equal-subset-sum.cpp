class Solution {
public:
bool t[202][200002];
    bool subsetSum(vector<int>&nums, int target){
        int n=nums.size();
    for(int j=0;j<=target;j++){t[0][j]=false;}
    for(int i=0;i<=n;i++){t[i][0]=true;}
     
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j-nums[i-1]]||t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
       for(int i=0;i<nums.size();i++){
        sum+=nums[i];
       } 
       bool ans;
       if(sum%2!=0)return false;
       else{
       ans=subsetSum(nums,sum/2);
       }
       return ans;
    }
};