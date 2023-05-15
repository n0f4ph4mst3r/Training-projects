#include <vector>

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
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    std::vector<int> buffer;

    void inorderTraversalBuff(TreeNode* root) {
        if (root == nullptr) return;
        inorderTraversal(root->left);
        buffer.push_back(root->val);
        inorderTraversal(root->right);
    }

    std::vector<int> inorderTraversal(TreeNode* root) {
        inorderTraversalBuff(root);
        return buffer;
    }
};