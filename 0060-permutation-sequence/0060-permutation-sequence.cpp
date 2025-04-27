class Solution {
public:
    int totalDigits;

    // Helper function to compute factorial of a number
    int computeFactorial(int n) {
        int result = 1;
        while (n > 1)
            result *= n--;
        return result;
    }

    // Returns the nth unused number and marks it as used
    string getNthUnusedDigit(vector<bool>& isUsed, int nthAvailable) {
        for (int i = 1; i <= totalDigits; i++) {
            if (!isUsed[i]) {
                nthAvailable--;
                if (nthAvailable == 0) {
                    isUsed[i] = true;
                    return to_string(i);
                }
            }
        }
        return "-1"; // This case should never happen
    }

    string getPermutation(int n, int k) {
        totalDigits = n;
        int blockSize = computeFactorial(n - 1); // Block size = (n-1)!
        vector<bool> isUsed(n + 1, false); // To track used digits (1-indexed)
        string result = "";

        while (n > 1) {
            // Determine which block k falls into
            int indexInBlock = k % blockSize == 0 ? blockSize : k % blockSize;
            int position = ceil((double)k / blockSize); // Determine position in available digits

            // Get the actual number at the 'position'-th unused spot
            result += getNthUnusedDigit(isUsed, position);

            // Update k and n for next iteration
            k = indexInBlock;
            n--;
            blockSize = computeFactorial(n - 1); // Recompute (n-1)! for next round
        }

        // Append the last unused digit
        for (int i = 1; i <= totalDigits; i++) {
            if (!isUsed[i]) {
                result += to_string(i);
                break;
            }
        }

        return result;
    }
};