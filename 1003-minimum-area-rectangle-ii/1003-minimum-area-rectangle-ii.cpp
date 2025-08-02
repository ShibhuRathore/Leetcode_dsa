class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        map<tuple<long long, long long, long long>, vector<pair<int,int>>> mp;
        double minArea = DBL_MAX;

        // Step 1: Store all diagonals
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long mx = points[i][0] + points[j][0];
                long long my = points[i][1] + points[j][1];
                long long dist = (long long)(points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) +
                                 (long long)(points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                mp[{mx, my, dist}].push_back({i, j});
            }
        }

        // Step 2: For each midpoint+distance, find rectangles
        for (auto &entry : mp) {
            auto &pairs = entry.second;
            if (pairs.size() < 2) continue;

            for (int a = 0; a < pairs.size(); a++) {
                for (int b = a + 1; b < pairs.size(); b++) {
                    auto [p1, p2] = pairs[a];
                    auto [p3, p4] = pairs[b];

                    // Use any point (e.g., p1) to form vectors
                    double vx1 = points[p3][0] - points[p1][0];
                    double vy1 = points[p3][1] - points[p1][1];
                    double vx2 = points[p4][0] - points[p1][0];
                    double vy2 = points[p4][1] - points[p1][1];

                    double area = abs(vx1 * vy2 - vy1 * vx2);
                    if (area > 0) minArea = min(minArea, area);
                }
            }
        }

        return minArea == DBL_MAX ? 0 : minArea;
    }
};
