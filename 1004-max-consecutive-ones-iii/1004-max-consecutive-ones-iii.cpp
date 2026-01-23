class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int i=0,j=0,n=nums.size(),maxlen=INT_MIN;
    for(j=0;j<n;j++){
        if(nums[j]==0)k--;
        while(k<0){
            if(nums[i]==0)k++;
            i++;
        }
        maxlen=max(maxlen,j-i+1);
    }
    return maxlen;
    }
};
