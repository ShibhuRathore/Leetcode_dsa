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
   bool check(TreeNode*p,TreeNode*q){
    // base case 
    if(!p&&!q) return true;
    if(p&&!q) return false;
    if(q&&!p) return false;
    bool value=(p->val==q->val);
    bool left=check(p->left, q->left);
    bool right=check(p->right,q->right);
    return (left&&right&&value);
   }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans=check(p,q);
        return ans;
    }
};