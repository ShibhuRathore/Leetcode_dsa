class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
     int left=0;
     int right=nums.size()-1;
     vector<int> ans(nums.size());
     int pos=nums.size()-1;
     while(left<=right){
        if(abs(nums[left])<abs(nums[right])){
            ans[pos]=nums[right]*nums[right];
            right--;
        }
        else{
            ans[pos]=nums[left]*nums[left];
            left++;
        }
        pos--;
     }
            return ans;
    }
};