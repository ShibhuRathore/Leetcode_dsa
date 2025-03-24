class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector< int >arr;
        int row = matrix.size();
        int col = matrix[0].size();
        for( int i = 0 ; i < row ; i++ ){
            for( int j = 0 ; j < col ; j++ ){
                if( matrix[i][j] == 0 ){
                    arr.push_back(i);
                    arr.push_back(j);
                }
            }
        }
        int n = arr.size();
        int a = 0;
        int x = 0;
        int y = 1;
        while( a < n/2 ){
            for( int i = 0 ; i < col ; i++){
                matrix[ arr[x] ][i] = 0;
            }
            for( int j = 0 ; j < row ; j++ ){
                matrix[j][ arr[y] ] = 0;
            }
            x += 2;
            y += 2;
            a++ ;
        }
    }
};