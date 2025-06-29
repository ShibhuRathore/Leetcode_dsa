class Solution {
public:
  vector<int> rank;
    vector<int>parent;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void union_find (int x, int y){
        int x_p=find(x);
        int y_p=find(y);
        if(x_p==y_p){
            return;

        }
        if(rank[x_p]==rank[y_p]){
            parent[y_p]=x_p;
            rank[x_p]++;
        }
        else if(rank[x_p]>y_p){
            parent[y_p]=x_p;
        }
        else{
            parent[x_p]=y_p;
        }
        
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            union_find(u,v);
        }
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            int parent=find(i);
            mp[parent]++;
        }
        long long result=0;
        long long remainingnodes=n;
        for(auto &P:mp){
          
            long long size=P.second;
            result+=(size)*(remainingnodes-size);
            remainingnodes-=size;
        }
        return result;
    }
};