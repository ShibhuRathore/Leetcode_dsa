class Solution {
public:

 bool isSafe(int newx,int newy,vector<vector<char>>&grid,vector<vector<bool>>&vis){
    if(newx>=0&&newy>=0&&newx<grid.size()&&newy<grid[0].size()&&grid[newx][newy]=='1'&&vis[newx][newy]==0){
        return true;
    }
    else{
        return false;
    }
 }
 void BFS(vector<vector<char>>&grid,vector<vector<bool>>&vis,int i , int j){
     int m=grid[0].size();
     int n=grid.size();
    queue<pair<int,int>>q;
    q.push({i,j});
    vis[i][j]=true;
    while(!q.empty()){
        auto src=q.front();
        q.pop();
        int x=src.first;
        int y=src.second;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(isSafe(nx,ny,grid,vis)){
                q.push({nx,ny});
                vis[nx][ny]=true;
            }
        }
    }
 }
 int numIslands(vector<vector<char>>& grid) {
     int count=0;
     int m=grid.size();
     int n=grid[0].size();
     vector<vector<bool>>vis(m,vector<bool>(n,false));

     for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
        if(vis[i][j]==false&&grid[i][j]=='1'){
            BFS(grid,vis,i,j);
            count++;
        }
       }
     }
     return count;
    }
};