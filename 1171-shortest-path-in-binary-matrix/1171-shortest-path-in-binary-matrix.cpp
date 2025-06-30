class Solution {
public:
    vector<vector<int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {-1, 1}, {1, -1}, {-1, -1}, {1, 1}
    };

    typedef pair<int, pair<int, int>> P;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0)
            return -1;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({1, {0, 0}});  // distance 1 from (0, 0)

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        result[0][0] = 1;

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            auto [row, col] = node;
            pq.pop();

            if (row == m - 1 && col == n - 1)
                return dist;

            // Skip if this is not the best distance to (row, col)
            if (dist > result[row][col]) continue;

            for (auto &dir : directions) {
                int new_row = row + dir[0];
                int new_col = col + dir[1];

                if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n &&
                    grid[new_row][new_col] == 0) {

                    if (dist + 1 < result[new_row][new_col]) {
                        result[new_row][new_col] = dist + 1;
                        pq.push({dist + 1, {new_row, new_col}});
                    }
                }
            }
        }

        return -1;
    }
};
