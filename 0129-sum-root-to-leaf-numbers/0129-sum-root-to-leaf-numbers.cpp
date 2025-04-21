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

    void solve(TreeNode* &root, int &output, int &ans) {
        // bc
        if (!root) return;

        // store curr output for bt
        int temp = output;
        // create temp val
        output = output*10 + root->val;

        // check the curr root is leaf or not
        if (!root->left && !root->right) {
            // add in ans
            cout << output << endl;
            ans += output;
            // bt
            output = temp;
            return;
        }

        // left and right call
        solve(root->left, output, ans);
        solve(root->right, output, ans);
        // bt
        output = temp;
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int output = 0;
        
        solve(root, output, ans);

        return ans;
    }
};