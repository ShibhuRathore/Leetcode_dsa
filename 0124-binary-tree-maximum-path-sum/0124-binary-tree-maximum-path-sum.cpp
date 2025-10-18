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
    int maxsum=INT_MIN;
    int solve(TreeNode*root){
       if (!root)return 0;
       int lh=solve(root->left);
       int rh=solve(root->right);
       int best_ans=max(lh,rh)+root->val;
       int neeche_ans=root->val+lh+rh;
       int root_ans=root->val;
       maxsum=max(max(root_ans,neeche_ans),max(best_ans,maxsum));
       return max(best_ans,root_ans);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxsum;
    }
};