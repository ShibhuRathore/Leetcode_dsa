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
int fin(vector<int> nums, int tr){
    for(int i = 0; i < nums.size();i++){
        if(nums[i] == tr) return i;
    }
    return -1;
}
TreeNode* sol(vector<int>& in, vector<int>& post, int instart , int inend , int& idx){
    if(idx < 0 || instart > inend) return NULL;

    TreeNode* ptr = new TreeNode(post[idx--]);  
    int newpos = fin(in,ptr->val);
 

    ptr->right = sol(in,post, newpos + 1 , inend , idx);
    ptr->left  = sol(in,post, instart , newpos - 1 , idx);
    return ptr;
};
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int start = 0;
        int end = postorder.size()-1;
        int pos = end;
        TreeNode* ans = sol(inorder,postorder,start,end,pos);
        return ans;
    }
};