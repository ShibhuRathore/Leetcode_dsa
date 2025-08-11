class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for (int i = 0; i <= 30; i++) {
            if ((n >> i) & 1) powers.push_back(i);
        }
        vector<int> prefix(powers.size() + 1, 0);
        for (int i = 0; i < powers.size(); i++) {
            prefix[i + 1] = prefix[i] + powers[i];
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int exp = prefix[q[1] + 1] - prefix[q[0]];
            ans.push_back((int)modPow(2, exp));
        }
        return ans;
    }
};