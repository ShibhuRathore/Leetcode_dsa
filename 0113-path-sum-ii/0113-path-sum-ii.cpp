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
    void solve(TreeNode* root, int targetSum, int sum, vector<int>& ans,
               vector<vector<int>>& result) {
        // base case
        if (root == NULL)
            return;

        // Include current node
        ans.push_back(root->val);
        sum += root->val;

        // Check for leaf node and target sum
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                result.push_back(ans);
            }
        }

        // left call
        solve(root->left, targetSum, sum, ans, result);

        // right call
        solve(root->right, targetSum, sum, ans, result);

        // backtrack
        ans.pop_back();
        sum = sum - root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> ans;
        solve(root, targetSum, 0, ans, result);
        return result;
    }
};