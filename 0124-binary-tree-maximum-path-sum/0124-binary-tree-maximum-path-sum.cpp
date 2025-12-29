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
    int solve(TreeNode* root){
        if(!root)return 0;
        int lh=solve(root->left);
        int rh=solve(root->right);
        int best_ans=root->val+max(lh,rh);
        int down_ans=root->val + lh +rh;
        int root_ans=root->val;
        maxsum=max(max(best_ans,down_ans),max(root_ans,maxsum));
        return max(root_ans,best_ans);
    }
    int maxPathSum(TreeNode* root) {
    
       solve(root);
      return maxsum;
    }
};