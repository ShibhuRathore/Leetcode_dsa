class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        unordered_set<int> possibleCosts;

        // Start with all base costs
        for (int base : baseCosts) {
            possibleCosts.insert(base);
        }

        // For each topping, update reachable costs with 0, 1, 2 units
        for (int topping : toppingCosts) {
            unordered_set<int> newCosts = possibleCosts;
            for (int cost : possibleCosts) {
                newCosts.insert(cost + topping);
                newCosts.insert(cost + 2 * topping);
            }
            possibleCosts = newCosts;
        }

        // Find the cost closest to target
        int closest = INT_MAX;
        for (int cost : possibleCosts) {
            if (abs(cost - target) < abs(closest - target) ||
                (abs(cost - target) == abs(closest - target) && cost < closest)) {
                closest = cost;
            }
        }

        return closest;
    }
};
