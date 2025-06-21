class Solution {
public:
    void DFS(vector<vector<char>>&grid,int i, int j, vector<vector<char>>&vis){
       
        int m=grid.size();
        int n=grid[0].size();
      if(i<0||i>=m|| j<0||j>=n||grid[i][j]=='0'||vis[i][j]=='1'){
        return;
      }
         vis[i][j]='1';
            DFS(grid,i+1,j,vis);
            DFS(grid,i-1,j,vis);
            DFS(grid,i,j+1,vis);
            DFS(grid,i,j-1,vis);
      
     
    }
    int numIslands(vector<vector<char>>& grid) {
     int m=grid.size();
     int n=grid[0].size();
     int count=0;
      vector<vector<char> >vis(m,vector<char>(n,'0'));
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'&&vis[i][j]=='0'){
                DFS(grid,i,j,vis);
                count++;
            }
        }
      }  
      return count;
    }
};