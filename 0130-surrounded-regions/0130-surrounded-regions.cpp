class Solution {
public:
    void DFS(vector<vector<char>>&board,vector<vector<bool>>&vis, int i, int j){
        int m=board.size();
        int n=board[0].size();
        if(i<0||i>=m||j<0||j>=n||vis[i][j]==true||board[i][j]=='X'){
            return;
        }
        vis[i][j]=true;
        DFS(board,vis,i+1,j);
        DFS(board,vis,i-1,j);
        DFS(board,vis,i,j+1);
        DFS(board,vis,i,j-1);

    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
      vector<vector<bool>>vis(m,vector<bool>(n,false));
      for( int i=0;i<n;i++){
        if(board[0][i]=='O'&&!vis[0][i]){
            DFS(board,vis,0,i);
        }
        if(board[m-1][i]=='O'&&!vis[m-1][i]){
            DFS(board,vis,m-1,i);
        }
      }
      for( int i=0;i<m;i++){
          if(board[i][0]=='O'&&!vis[i][0]){
            DFS(board,vis,i,0);
          }
          if(board[i][n-1]=='O'&&!vis[i][n-1]){
            DFS(board,vis,i,n-1);
          }
      }
     for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]==false&&board[i][j]=='O'){
                board[i][j]='X';
            }
        }
     }
     return;
    }
};