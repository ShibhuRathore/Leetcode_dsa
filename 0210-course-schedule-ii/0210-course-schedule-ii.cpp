class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        for(auto &vec:prerequisites){
            int u=vec[1];
            int v=vec[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        vector<int>res;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int source=q.front();
            q.pop();
            res.push_back(source);
            for(auto &v:adj[source]){
                indegree[v]--;
             if(indegree[v]==0){
                q.push(v);
             }
            }
        }
        if (res.size() != n) {
            return {};
        }
        return res;
    }
};