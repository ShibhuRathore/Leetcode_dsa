class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;  // stores indices (monotonic decreasing stack)

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;  // number of days to wait
            }
            st.push(i);
        }

        return ans;
    }
};
