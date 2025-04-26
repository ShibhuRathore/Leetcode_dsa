class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int> us(nums.begin(),nums.end());
        int temp=INT_MIN;
        for(auto e:us){
            if(temp!=INT_MIN)us.erase(temp);
            if(us.find(e-1)==us.end()){
                int count=1;
                int cur=e+1;
                temp=e;
                while(us.find(cur)!=us.end()){
                    us.erase(cur);
                    cur++;
                    count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};