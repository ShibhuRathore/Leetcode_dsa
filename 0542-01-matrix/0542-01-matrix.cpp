class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>result(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    result[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int>P=q.front();
            q.pop();
            int x=P.first;
            int y=P.second;
            for(auto &dir:directions){
                int newx=x+dir[0];
                int newy=y+dir[1];
                if(newx>=0&&newx<m&&newy>=0&&newy<n&&result[newx][newy]==-1){
                    result[newx][newy]=1+result[x][y];
                    q.push({newx,newy});
                }
            }
        }
        return result;
    }
};