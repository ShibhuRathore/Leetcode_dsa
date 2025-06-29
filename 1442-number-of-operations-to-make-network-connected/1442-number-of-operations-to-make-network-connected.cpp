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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int components=n;
        for( auto &vec:connections){
            int u=vec[0];
            int v=vec[1];
          int u_p = find(u);
          int v_p = find(v);
          if(u_p!=v_p){
            components--;
            union_find(u_p,v_p);
          }
        }
        return components-1;
    }
};