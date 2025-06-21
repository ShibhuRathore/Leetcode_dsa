class Solution {
public:
    void DFS(vector<vector<int>>& heights, int i , int j , vector<vector<bool>>&oceans,vector<vector<int>>&results){
         int m=heights.size(); 
       int n=heights[0].size();
        if(i<0||i>=m||j<0||j>=n||oceans[i][j]==true){
            return;
        } 
        oceans[i][j]=true;
        if(i + 1 < m &&heights[i][j]<=heights[i+1][j]){
            DFS(heights,i+1,j,oceans,results);
        }
          if(i - 1 >= 0 &&heights[i][j]<=heights[i-1][j]){
            DFS(heights,i-1,j,oceans,results);
        }  
        if(j + 1 < n &&heights[i][j]<=heights[i][j+1]){
            DFS(heights,i,j+1,oceans,results);
        }  
        if(j - 1 >= 0&&heights[i][j]<=heights[i][j-1]){
            DFS(heights,i,j-1,oceans,results);
        }
      

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       int m=heights.size(); 
        if (m == 0) return {};
       int n=heights[0].size();
       vector<vector<bool>>pacific(m,vector<bool>(n,false));
       vector<vector<bool>>atlantic(m,vector<bool>(n,false));
       vector<vector<int>>result;
       //pacific-top
       for(int i=0;i<n;i++){
        DFS(heights,0,i,pacific,result);
       }
       //pacific -left
       for(int i=0;i<m;i++){
        DFS(heights,i,0,pacific,result);
       }
       //atlantic-bottom
       for(int i=0;i<n;i++){
        DFS(heights,m-1,i,atlantic,result);
       }
       for(int i=0;i<m;i++){
        DFS(heights,i,n-1,atlantic,result);
       }
       for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }


  return result;
    }
};