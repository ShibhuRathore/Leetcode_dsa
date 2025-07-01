class Solution {
public:

  typedef pair<int,int> P;
    int prims(vector<vector<P>>&adj, int size){
        priority_queue<P, vector<P>, greater<P>> pq;       
          pq.push({0,0});
        vector<int>vis(size,false);
        int sum=0;
        while(!pq.empty()){
            int weight=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node]==true){
                continue;
            }
            sum+=weight;
            vis[node]=true;
            for(auto &nbr:adj[node] ){
                int n_node=nbr.first;
                int n_wt=nbr.second;

                if(vis[n_node]==false){
                    pq.push({n_wt,n_node});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size=points.size();
        vector<vector<P>> adj(size);
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int d=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
     return  prims(adj,size);
    }
};