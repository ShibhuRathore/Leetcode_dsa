class Solution {
public:
    static int N;
    static const int MOD = 1000000007;

    // dp[i][people][p] = number of ways from index i, using exactly 'people' people,
    // with current profit 'p' (capped at minProfit)
    int solve(int i, int people, int pr, int &minProfit,
              vector<int>& group, vector<int>& profit,
              vector<vector<vector<int>>>& dp) {

        if (people > N) return 0;                    // over capacity
        if (pr > minProfit) pr = minProfit;          // cap profit for state compression

        if (i == (int)group.size()) {                // all jobs considered
            return (pr >= minProfit) ? 1 : 0;
        }

        int &memo = dp[i][people][pr];
        if (memo != -1) return memo;

        // choose job i
        int taken = solve(i + 1, people + group[i], pr + profit[i],
                          minProfit, group, profit, dp);
        // skip job i
        int not_taken = solve(i + 1, people, pr, minProfit, group, profit, dp);

        long long ans = (taken + 0LL + not_taken) % MOD;
        return memo = (int)ans;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        N = n;
        int m = (int)group.size();

        // dp size: m x (N+1) x (minProfit+1)
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(N + 1, vector<int>(minProfit + 1, -1))
        );

        return solve(0, 0, 0, minProfit, group, profit, dp);
    }
};

int Solution::N = 0;
