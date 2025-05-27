class NumMatrix {
    vector<vector<int>> ps; 
public:
    int m;
    int n;
     vector<vector<int>>prefix;
    NumMatrix(vector<vector<int>>& mt) {
         m=mt.size();
         n=mt[0].size();
    prefix.resize(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            prefix[i][j]=mt[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
    }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
    int r1=row1+1;
    int c1=col1+1;
    int r2=row2+1;
    int c2=col2+1;
    return prefix[r2][c2]-prefix[r1-1][c2]-prefix[r2][c1-1]+prefix[r1-1][c1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */