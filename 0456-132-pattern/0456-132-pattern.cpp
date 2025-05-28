class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    int second = INT_MIN; // this stores the "2" in 132
    stack<int> st; // used to keep possible "3" values

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // if we find a number smaller than "second", we found pattern
        if (nums[i] < second) {
            return true;
        }

        // keep popping while current > top, updating "second"
        while (!st.empty() && nums[i] > st.top()) {
            second = st.top();
            st.pop();
        }

        // push current number as a possible "3"
        st.push(nums[i]);
    }

    return false; 
    }
};