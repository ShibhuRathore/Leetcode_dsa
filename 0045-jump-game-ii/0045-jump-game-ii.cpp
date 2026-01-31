class Solution {
public:
    int jump(vector<int>& nums) {
    int farthest=0;
    int jump=0;
    int currentend=0;
    int n=nums.size();
    for(int i=0;i<n-1;i++){
      farthest=max(farthest,i+nums[i]);
      if(i==currentend){
        jump++;
        currentend=farthest;
      }
    }
    return jump;
    }

};