class Solution {
public:
    int minimumLines(vector<vector<int>>& nums) {
         if (nums.size() <= 1) return 0;
    sort(nums.begin(), nums.end());
     long long x=nums[0][0];
     long long y=nums[0][1];
     int count=1;
     for(int i=1;i<nums.size()-1;i++){
        long long x2=nums[i][0],y2=nums[i][1];
        long long x3=nums[i+1][0],y3=nums[i+1][1];
        if((y2-y)*(x3-x)!=(y3-y)*(x2-x)){
            count ++;
            x=x2;
            y=y2;
        }

     }
     return count;
    }
};