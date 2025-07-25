class Solution {
public:
    bool carPooling(vector<vector<int>>& trip, int capacity) {
        vector<int>ans(10001,0);
     for(auto &vec:trip){
        int pass=vec[0];
        int from=vec[1];
        int to=vec[2];

        ans[from]+=pass;
        
        ans[to]-=pass;
        }
        vector<int>prefix(ans.size(),0);
        
        prefix[0]=ans[0];
        if(prefix[0]>capacity)return false;
        for(int i=1;i<ans.size();i++){
            prefix[i]=ans[i]+prefix[i-1];
            if(prefix[i]>capacity)return false;
        }
     
     return true;
    }
};