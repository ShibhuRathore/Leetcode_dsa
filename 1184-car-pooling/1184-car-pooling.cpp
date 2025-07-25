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
        int sum=0;
        
      
      
        for(int i=0;i<ans.size();i++){
           sum+=ans[i];
            if(sum>capacity)return false;
        }
     
     return true;
    }
};