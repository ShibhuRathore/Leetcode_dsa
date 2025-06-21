class Solution {
public:
    void BFS(int u,vector<vector<int>>&adj,vector<bool>&vis){
     queue<int> q;
     q.push(u);
    vis[u]=true;
     while(!q.empty()){
        int source=q.front();
        q.pop();
        for(auto &v:adj[source]){
            if(!vis[v]){
                q.push(v);
                vis[v]=true;
            }
        }
     }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<vector<int>>adj(V);
     vector<bool>vis(V,false);
     for( int i =0;i<V;i++){
        for( int j=0;j<V;j++){
            if(isConnected[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
     }
    
     int count=0;
     for(int i =0;i<V;i++){
        if (vis[i]==false){
            BFS(i,adj,vis);
            count++;
        }
     }
     return count;
    }
};