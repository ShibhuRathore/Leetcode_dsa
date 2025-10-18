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
        if(!root) return 0;
        int left=solve(root->left);
        int right=solve(root->right);
        int neeche_hi_ans=left+root->val+right;
        int koi_ek_acha=max(left,right)+root->val;
        int keval_root_acha=root->val;
        maxsum=max(max(maxsum,neeche_hi_ans),max(koi_ek_acha,keval_root_acha));
        return max(koi_ek_acha,keval_root_acha);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxsum;
    }
};