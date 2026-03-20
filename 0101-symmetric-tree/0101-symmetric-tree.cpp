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
   bool ismirror(TreeNode*p,TreeNode*q){
    if(!p&&!q)return true;
    if(p&&!q)return false;
    if(q&&!p)return false;
    bool value=(p->val==q->val);
    bool check1=ismirror(p->left,q->right);
    bool check2=ismirror(p->right,q->left);
    return (value&&check1&&check2);
   }
    bool isSymmetric(TreeNode* root) {
     return ismirror(root->left,root->right);
    }
};