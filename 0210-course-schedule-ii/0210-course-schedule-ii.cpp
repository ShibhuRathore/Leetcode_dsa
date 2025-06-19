class Solution {
public:

   void DFS(vector<vector<int>>&adj, int u, vector<bool>&vis, vector<bool>&inrecursion,stack<int>&st){
      vis[u]=true;
      inrecursion[u]=true;
      for(auto &v:adj[u]){
        if(vis[v]==false){
            DFS(adj,v,vis,inrecursion,st);
        }
        else if(inrecursion[v]==true){
            return;
        }
      }
      st.push(u);
      inrecursion[u]=false;
      
   }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<bool>inrecursion(n,false);
        stack<int>st;
        vector<bool>vis(n,false);
        for(auto &vec:prerequisites){
            int u=vec[1];
            int v=vec[0];
            adj[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                DFS(adj,i,vis,inrecursion,st);
            }
        }
        vector<int>res;
        while(!st.empty()){
           res.push_back(st.top()) ;
           st.pop();
        }
        if(res.size()!=n){
            return {};
        }
        return res;
    }
};