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

    TreeNode* sortedArrayToBST(std::vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int i = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[i]);
        node->left = sortedArrayToBST(nums, left, i - 1);
        node->right = sortedArrayToBST(nums, i + 1, right);
        return node;
    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if (nums.empty()) return nullptr;
        else return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};