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
    vector<string>v;

    void check(TreeNode* root,string path,vector<string>&result){
     if(!root) return;
     if(!path.empty()) path+="->";
     path+=to_string(root->val);
     if(root->left==NULL&&root->right==NULL){
        result.push_back(path);
        return;
     }
     check(root->left,path,result);
     check(root->right,path,result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        string path="";
        check(root,path,result);
        return result;
    }
};