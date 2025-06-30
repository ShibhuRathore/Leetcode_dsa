class Solution {
public:
    vector<vector<int>> directions = {
    {1,0}, {-1,0}, {0,1}, {0,-1},
    {-1,1}, {1,-1}, {-1,-1}, {1,1}
};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
     int m=grid.size();
     int n=grid[0].size();
      if (grid[0][0] != 0 || grid[m-1][n-1] != 0) return -1;
     queue<pair<int,int>>q;
     int level=0;
     q.push({0,0}); 
     grid[0][0] = 1; // Distance (instead of visited array)

     while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
        auto P=q.front();
        q.pop();
        int row=P.first;
        int col=P.second;
        if (row == m - 1 && col == n - 1) return level+1;
        
            for( auto &dir:directions){
               int new_row=row+dir[0];
               int new_col=col+dir[1];

                if(new_row>=0&&new_row<m&&new_col>=0&&new_col<n&&grid[new_row][new_col]==0){
                    q.push({new_row,new_col});
                    grid[new_row][new_col]=1;
                }
            }
        }
      level++;
     }return -1;
    }
};