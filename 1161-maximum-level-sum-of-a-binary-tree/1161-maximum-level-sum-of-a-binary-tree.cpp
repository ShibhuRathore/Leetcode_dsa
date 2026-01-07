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
    int maxLevelSum(TreeNode* root) {
        if(!root)return 0;
       queue<TreeNode*>q;
       map<int,int>mp;
       q.push(root);
       int j=0;
       while(!q.empty()){
        int size=q.size();
        int sum=0;
        for(int i =0;i<size;i++){
            TreeNode* temp=q.front();
          sum+=q.front()->val;
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
          q.pop(); 
        }
        mp[j]=sum;
        j++;
       }
       int greatestsum=INT_MIN;
       int ans=0;
       for(auto &it:mp){
        if(greatestsum<it.second){
            greatestsum=it.second;
            ans=it.first+1;
        }
       }
       return ans;
    }
};