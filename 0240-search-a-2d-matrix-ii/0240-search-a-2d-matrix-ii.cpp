class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();            // number of rows
        int n = matrix[0].size();         // number of columns

        int row = 0, col = n - 1;         // start from top-right corner

        while (row < m && col >= 0) {
            int val = matrix[row][col];

            if (val == target) return true;      // found the target
            else if (val > target) col--;        // move left
            else row++;                          // move down
        }

        return false;    // target not found
    }
};