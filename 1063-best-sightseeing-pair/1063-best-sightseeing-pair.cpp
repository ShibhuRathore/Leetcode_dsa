class Solution {
public:
    int maxScoreSightseeingPair(const std::vector<int>& values) {
    int max_score = INT_MIN;         // Variable to keep track of the maximum score found so far
    int max_i = values[0] + 0;       // Initialize max_i as values[0] + 0 (best i for j=1 initially)

    // Iterate through all possible j (start from 1 since i < j)
    for (int j = 1; j < values.size(); ++j) {
        // For each j, calculate the score using the best i seen so far (max_i)
        int current_score = max_i + values[j] - j;

        // Update max_score if the current_score is greater
        if (current_score > max_score) {
            max_score = current_score;
        }

        // Update max_i for the next iteration, so that it always holds the best possible values[i] + i
        int candidate = values[j] + j;
        if (candidate > max_i) {
            max_i = candidate;
        }
    }

    return max_score;
}
};