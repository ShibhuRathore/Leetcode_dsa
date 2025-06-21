class Solution {
public:
    void DFS(vector<vector<int>>&image , int i, int j, int color,int prevcolor){
        int m=image.size();
        int n=image[0].size();
        if(i<0||i>=m||j<0||j>=n||image[i][j]==color||image[i][j]!=prevcolor){
            return ;
        }
        image[i][j]=color;
        DFS(image,i+1,j,color,prevcolor);
        DFS(image,i-1,j,color,prevcolor);
        DFS(image,i,j+1,color,prevcolor);
        DFS(image,i,j-1,color,prevcolor);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevcolor=image[sr][sc];
        DFS(image,sr,sc,color,prevcolor);
        return image;
    }
};