class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> numset(nums.begin(),nums.end());
       int longestStreak=0;
      
       for(auto &num:numset){
        if(numset.find(num-1)==numset.end()){
            int currnum=num;
            int currstreak=1;
              while(numset.find(currnum+1)!=numset.end()){
            currstreak+=1;
            currnum=currnum+1;
        }
        longestStreak=max(currstreak,longestStreak);
        }
       
       }
       return longestStreak;
    }
};