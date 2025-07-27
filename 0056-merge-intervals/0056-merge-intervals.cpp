class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;

        while (i < n) {
            // Initialize start and end for the current interval
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Merge all overlapping intervals
            while (i < n - 1 && intervals[i + 1][0] <= end) {
                end = max(end, intervals[i + 1][1]);
                i++;
            }

            // Push the merged interval
            ans.push_back({start, end});
            i++;
        }

        return ans;
    }
};
