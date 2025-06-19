class Solution {
public:
    void DFS(int u,vector<vector<int>>&adj,vector<bool>&vis){
        vis[u]=true;
        for(auto &v:adj[u]){
            if(vis[v]==false){
                DFS(v,adj,vis);
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
            DFS(i,adj,vis);
            count++;
        }
     }
     return count;
    }
};