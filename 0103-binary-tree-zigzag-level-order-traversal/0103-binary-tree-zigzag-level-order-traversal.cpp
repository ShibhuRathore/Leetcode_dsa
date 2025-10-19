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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     if(!root )return {};
     vector<vector<int>>result;
     queue<TreeNode*>q;
     q.push(root);
     bool flag=false;
     while(!q.empty()){
        vector<int>ans;
        int size=q.size();
        
        for(int i=0;i<size;i++){
        TreeNode* curr=q.front();
        q.pop();
        if(curr->left){q.push(curr->left);}
        if(curr->right){q.push(curr->right);}
        ans.push_back(curr->val);
        }
        if(flag){
            reverse(ans.begin(),ans.end());
        }
        flag=!flag;
        result.push_back(ans);
     }
     return result;
    }
};