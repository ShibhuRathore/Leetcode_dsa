class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &vec:times){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];
            adj[u].push_back({v,w});
           
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});

        vector<int>result(n+1,INT_MAX);
        result[k]=0;
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &vec:adj[node]){
                int n_node=vec.first;
                int d=vec.second;
                if(d+dist<result[n_node]){
                    result[n_node]=d+dist;
                    pq.push({d+dist,n_node});
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (result[i] == INT_MAX) return -1;
            maxTime = max(maxTime, result[i]);
        }
        return maxTime;
    }
};