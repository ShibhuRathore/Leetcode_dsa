class Solution {
public:
    // Helper function to create a unique hash key for visited state
    string makeKey(int pos, int speed) {
        return to_string(pos) + "," + to_string(speed);
    }

    int racecar(int target) {
        // Queue stores: {position, speed, steps}
        queue<tuple<int, int, int>> q;
        q.push({0, 1, 0});  // start at position 0, speed +1, 0 steps

        // Set to keep track of visited states: (position, speed)
        unordered_set<string> visited;
        visited.insert(makeKey(0, 1));

        while (!q.empty()) {
            auto [pos, speed, steps] = q.front();
            q.pop();

            // If we've reached the target, return the steps taken
            if (pos == target) return steps;

            // ------------------------------
            // Option 1: Accelerate ('A')
            int newPos = pos + speed;
            int newSpeed = speed * 2;
            string keyA = makeKey(newPos, newSpeed);

            // We limit the state space to prevent infinite loop or overshoot
            if (abs(newPos) <= 2 * target && visited.find(keyA) == visited.end()) {
                visited.insert(keyA);
                q.push({newPos, newSpeed, steps + 1});
            }

            // ------------------------------
            // Option 2: Reverse ('R')
            int reverseSpeed = speed > 0 ? -1 : 1;
            string keyR = makeKey(pos, reverseSpeed);

            if (visited.find(keyR) == visited.end()) {
                visited.insert(keyR);
                q.push({pos, reverseSpeed, steps + 1});
            }
        }

        return -1;  // control should never reach here
    }
};