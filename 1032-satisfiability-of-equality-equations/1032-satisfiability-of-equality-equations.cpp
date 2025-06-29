class Solution {
public:
vector<int> parent;
vector<int> rank;

int find(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=find(parent[x]);
}
void union_find(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);
    if(x_parent==y_parent){
        return;
    }
    if(rank[x_parent]==rank[y_parent]){
        parent[x_parent]=y_parent;
        rank[y_parent]++;
    }
    else if(rank[y_parent]>rank[x_parent]){
        parent[x_parent]=y_parent;
    }
    else{
        parent[y_parent]=x_parent;
    }
}
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for( auto &s:equations){
            if(s[1]=='='){
                union_find(s[0]-'a',s[3]-'a');
            }
        }
        for(auto &s:equations){
            if(s[1]=='!'){
                int first=s[0];
                int second=s[3];
                int first_p=find(s[0]-'a');
                int second_p=find(s[3]-'a');
                if(first_p==second_p){
                    return false;
                }
            }
        }
        return true;
    }
};