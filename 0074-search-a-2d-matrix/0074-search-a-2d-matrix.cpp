//flatten the grid into 1 D array


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int m = matrix.size();            // number of rows
        int n = matrix[0].size();         // number of columns
        int left=0;
        int right=(m*n-1);
        while(left<=right){
            int mid=left+(right-left)/2;
            int row=mid/n;
            int col=mid%n;
            if(matrix[row][col]==target){return true;}
            else if(matrix[row][col]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return false;
    }
};