class Solution {
public:

    // Helper function: Performs DFS to simulate the chain of detonations
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, int& count) {
        visited[node] = true; // Mark this bomb as detonated
        count++; // Increment the number of bombs detonated in this chain

        // Traverse all bombs that are directly in range of this bomb
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, count); // Recurse for each undetonated neighbor
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(); // Number of bombs
        vector<vector<int>> graph(n); // Adjacency list to represent which bomb can detonate which other bomb

        // ------------------------------
        // STEP 1: Build the directed graph
        // ------------------------------
        for (int i = 0; i < n; ++i) {
            // Coordinates and radius of bomb i
            long long xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];

            for (int j = 0; j < n; ++j) {
                if (i == j) continue; // Skip self-comparison

                // Coordinates of bomb j
                long long xj = bombs[j][0], yj = bombs[j][1];

                // Compute the squared Euclidean distance between bomb i and bomb j
                long long dx = xi - xj;
                long long dy = yi - yj;
                long long distSq = dx * dx + dy * dy;

                // Compare with the square of radius to avoid using sqrt()
                // If bomb j is within the range of bomb i, add a directed edge i → j
                if (distSq <= ri * ri) {
                    graph[i].push_back(j);
                }
            }
        }

        int maxDetonated = 0; // Stores the maximum number of bombs we can detonate

        // ------------------------------
        // STEP 2: Try detonating each bomb as the starting point
        // ------------------------------
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false); // Tracks which bombs have been detonated in this simulation
            int count = 0; // Number of bombs detonated starting from bomb i

            // Start DFS from bomb i to simulate a full detonation chain
            dfs(i, graph, visited, count);

            // Update the answer with the maximum bombs detonated
            maxDetonated = max(maxDetonated, count);
        }

        return maxDetonated; // Final result
    }
};
