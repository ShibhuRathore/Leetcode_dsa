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
    TreeNode* getMin(TreeNode* curr){
        while(curr->left){curr=curr->left;}
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val>key){
           root->left= deleteNode(root->left,key);
        }
      else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(!root->left){
                TreeNode*rightchild=root->right;
                delete root;
                 return rightchild;
            }
            if(!root->right){
                TreeNode*leftchild=root->left;
                delete root;
                return leftchild;
            }
            TreeNode *successor=getMin(root->right);
            root->val=successor->val;
            root->right=deleteNode(root->right,successor->val);
        }
        return root;
    }
};