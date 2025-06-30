class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty()) {
            auto [effort, node] = pq.top();
            auto [row, col] = node;
            pq.pop();

            if (row == m - 1 && col == n - 1)
                return effort;

            for (auto &dir : directions) {
                int new_row = row + dir[0];
                int new_col = col + dir[1];

                if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n) {
                    int curr_diff = abs(heights[row][col] - heights[new_row][new_col]);
                    int max_effort = max(effort, curr_diff);

                    if (max_effort < result[new_row][new_col]) {
                        result[new_row][new_col] = max_effort;
                        pq.push({max_effort, {new_row, new_col}});
                    }
                }
            }
        }

        return 0; // fallback (theoretically unreachable)
    }
};
