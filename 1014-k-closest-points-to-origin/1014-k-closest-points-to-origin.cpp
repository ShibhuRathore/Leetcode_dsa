class Solution {
public:
   using P = pair<int, pair<int, int>>;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<P,vector<P>,greater<P>>pq;
       for(auto &vec:points){
        int u=vec[0];
        int v=vec[1];
        int dist=((u*u)+(v*v));
        pq.push({dist,{u,v}});
       } 

       vector<vector<int>>ans;
       while(k){
        auto top=pq.top();
        pq.pop();
         int u= top.second.first;
         int v=top.second.second;
         ans.push_back({u,v});
         k--;
       }
       return ans;
    }
};