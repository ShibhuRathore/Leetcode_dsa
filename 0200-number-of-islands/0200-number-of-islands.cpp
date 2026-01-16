class Solution {
public:

bool isSafe(vector<vector<char>>&grid,int i,int j, vector<vector<bool>>&vis){
    int m=grid.size();
    int n=grid[0].size();
    if(i<0||i>=m||j<0||j>=n||grid[i][j]=='0'||vis[i][j]==true)return false;
    return true;
}
 void dfs(vector<vector<char>>&grid,int i, int j,vector<vector<bool>>&vis){
    vis[i][j]=true;
    int dx[]={1,-1,0,0};
    int dy[]={0,0,-1,1};
    for(int k=0;k<4;k++){
        int n_x=i+dx[k];
        int n_y=j+dy[k];
        if(isSafe(grid,n_x,n_y,vis))dfs(grid,n_x,n_y,vis);
    }
    
 }
 int numIslands(vector<vector<char>>& grid) {
     int count=0;
     int m=grid.size();
     int n=grid[0].size();
     vector<vector<bool>>vis(m,vector<bool>(n,false));
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'&&!vis[i][j]){
                dfs(grid,i,j,vis);
                count++;
            }
        }
     }
     return count;
    }
};