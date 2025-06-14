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
    unordered_map<string,int> mp;
    vector<TreeNode*>res;
    string serialize(TreeNode*root){
     if(! root) return"";
     string left=serialize(root->left);
     string right=serialize(root->right);
     string curr=to_string(root->val);
      curr=curr+","+left+","+right;
      mp[curr]++;
      if(mp[curr]==2){
        res.push_back(root);
      }
      return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      serialize(root);
      return res;}
};