/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxFreq = 0;
    unordered_map<int, int> cnt;

    int dfs(TreeNode* root) {
        if (root == NULL) return 0;

        int leftValue = dfs(root->left);
        int rightValue = dfs(root->right);

        int currentValue = leftValue + rightValue + root->val;
        cnt[currentValue]++;
        maxFreq = max(maxFreq, cnt[currentValue]);

        return currentValue;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        dfs(root);
        for (auto &x : cnt) {
            if (x.second == maxFreq)
                ans.push_back(x.first);
        }
        return ans;
    }   
};