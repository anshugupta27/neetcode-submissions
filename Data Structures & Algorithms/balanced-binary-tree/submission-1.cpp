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
    int isBalancedDfs (TreeNode* root, bool &isBalancedTree) {
        if (!root) return 0;
        int left = isBalancedDfs (root -> left, isBalancedTree);
        int right = isBalancedDfs (root -> right, isBalancedTree);
        if (abs(left - right) > 1) {
            isBalancedTree = false;
        }
        return max (right, left) + 1;

    }
    bool isBalanced(TreeNode* root) {
        bool isBalancedTree = true;
        isBalancedDfs (root, isBalancedTree);
        return isBalancedTree;
    }
};