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
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function to recursively prune the tree
    TreeNode* pruneSubtree(TreeNode* root) {
        // Base case: if current node is null, return null
        if (root == nullptr) return nullptr;

        // Recursively prune the left and right subtrees
        root->left = pruneSubtree(root->left);
        root->right = pruneSubtree(root->right);

        // After pruning, if the current node is 0 and both children are null
        // then this subtree does not contain a 1 → prune this node
        if (root->val == 0 && root->left == nullptr && root->right == nullptr)
            return nullptr;

        // Otherwise, keep the node
        return root;
    }

    // Public function to start pruning from root
    TreeNode* pruneTree(TreeNode* root) {
        return pruneSubtree(root);
    }
};
