class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
       int m =mat.size();
       int n=mat[0].size();
       vector<vector<int>>prefix(m+1,vector<int>(n+1,0));
       for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            prefix[i][j]=mat[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
       }
       vector<vector<int>>result(m,vector<int>(n,0));
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int r1=max(i-k,0);
            int c1=max(j-k,0);
            int r2=min(k+i,m-1);
            int c2=min(k+j,n-1);
            r1++;
            c1++;
            r2++;
            c2++;
            result[i][j]=prefix[r2][c2]-prefix[r1-1][c2]-prefix[r2][c1-1]+prefix[r1-1][c1-1];
        }
       }
       return result;
    }
};