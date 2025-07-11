class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;  // {wage/quality ratio, quality}

        // Step 1: Calculate ratio and store with quality
        for (int i = 0; i < n; ++i) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }

        // Step 2: Sort workers by ratio (ascending)
        sort(workers.begin(), workers.end());

        priority_queue<int> maxHeap;  // to keep k smallest qualities
        int sumQuality = 0;
        double minCost = DBL_MAX;

        // Step 3: Iterate and maintain heap of k workers
        for (auto& [ratio, q] : workers) {
            sumQuality += q;
            maxHeap.push(q);

            if (maxHeap.size() > k) {
                sumQuality -= maxHeap.top();  // remove largest quality
                maxHeap.pop();
            }

            if (maxHeap.size() == k) {
                double cost = sumQuality * ratio;
                minCost = min(minCost, cost);
            }
        }

        return minCost;
    }
};
