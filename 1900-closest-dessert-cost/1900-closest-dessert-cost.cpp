class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int closest = INT_MAX; // Store the closest cost found so far

        // Helper function for DFS over toppings
        function<void(int, int)> dfs = [&](int index, int currentCost) {
            // Update closest if this cost is better
            if (abs(currentCost - target) < abs(closest - target) ||
                (abs(currentCost - target) == abs(closest - target) && currentCost < closest)) {
                closest = currentCost;
            }

            // Base case: if we’ve used all toppings, return
            if (index == toppingCosts.size()) return;

            // Choice 1: Use 0 of current topping
            dfs(index + 1, currentCost);

            // Choice 2: Use 1 of current topping
            dfs(index + 1, currentCost + toppingCosts[index]);

            // Choice 3: Use 2 of current topping
            dfs(index + 1, currentCost + 2 * toppingCosts[index]);
        };

        // Try DFS starting from each base cost
        for (int base : baseCosts) {
            dfs(0, base);
        }

        return closest;
    }
};
