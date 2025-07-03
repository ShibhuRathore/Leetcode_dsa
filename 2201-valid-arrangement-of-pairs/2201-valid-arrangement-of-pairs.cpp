class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
      
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;
        for(auto &vec:pairs){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }
        // finding start node
          int start=-1;
         for(auto &it:adj){
             int node=it.first;
            if(outdegree[node]-indegree[node]==1){
                start=node;
                break;
            }
        }
        vector<int>path;
        stack<int>st;
        if (start == -1) {
    start = pairs[0][0];  // Any node is valid if it's an Eulerian circuit
        }
        st.push(start);
        while(!st.empty()){
            int node=st.top();
            if(!adj[node].empty()){
                int nbr=adj[node].back();
                adj[node].pop_back();
                st.push(nbr);
            }
            else{
                path.push_back(node);
                st.pop();
            }
        }
        reverse(path.begin(),path.end());
        vector<vector<int>>result;
        for(int i=0;i<path.size()-1;i++){
            result.push_back({path[i],path[i+1]});
        }
     return result;
    }
};