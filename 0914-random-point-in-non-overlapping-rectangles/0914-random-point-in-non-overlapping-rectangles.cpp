class Solution {
public:
    vector<vector<int>> rects;      // Stores rectangles as [a, b, x, y]
    vector<int> prefixSums;    
   Solution(vector<vector<int>>& rects) : rects(rects) {
        srand(time(0));   // Seed the random number generator once
        int sum = 0;
        prefixSums.reserve(rects.size());
        for (const auto& rect : rects) {
            int a = rect[0], b = rect[1], x = rect[2], y = rect[3];
            int points = (x - a + 1) * (y - b + 1); // Number of integer points in rectangle
            sum += points;
            prefixSums.push_back(sum); // Store running total
        }
    }
     int findRectIndex(int k) {
        // lower_bound returns the first index where prefixSums[idx] >= k
        return lower_bound(prefixSums.begin(), prefixSums.end(), k) - prefixSums.begin();
    }
    vector<int> pick() {
        int totalPoints = prefixSums.back();
        // Generate a random number k in [1, totalPoints]
        int k = (rand() % totalPoints) + 1;

        // Find which rectangle contains the k-th point
        int rectIdx = findRectIndex(k);
        const auto& rect = rects[rectIdx];
        int a = rect[0], b = rect[1], x = rect[2], y = rect[3];
        int width = x - a + 1;

        // Calculate the offset (0-based) within this rectangle
        int prevSum = rectIdx == 0 ? 0 : prefixSums[rectIdx - 1];
        int offset = k - prevSum - 1;

        // Map offset to (dx, dy) inside the rectangle
        int dx = offset % width;
        int dy = offset / width;

        // Return the integer coordinate
        return {a + dx, b + dy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */