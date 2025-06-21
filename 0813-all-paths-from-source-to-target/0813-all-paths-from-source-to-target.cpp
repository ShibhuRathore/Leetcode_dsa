class Solution {
public:
   void DFS(vector<vector<int>>&graph,int u, int target, vector<int>&temp,vector<vector<int>>&result){
       temp.push_back(u);
       if(u==target){
        result.push_back(temp);
       }
       else{
         for(auto&v:graph[u]){
         DFS(graph,v,target,temp,result);
       }
       }
      
      temp.pop_back();
   }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>result;
        vector<int>temp;
        DFS(graph,0,n-1,temp,result);
        return result;
    }
};