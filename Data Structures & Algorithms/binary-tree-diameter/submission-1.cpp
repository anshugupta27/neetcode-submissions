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
    int diameterOfBinaryTreeDfs (TreeNode* root, int &finalDiameter) {
        if (!root) return 0;
        int left = diameterOfBinaryTreeDfs (root -> left, finalDiameter);
        int right = diameterOfBinaryTreeDfs (root -> right, finalDiameter);
        finalDiameter = max ({finalDiameter, right + left , right, left});
        return max (right + 1, left + 1) ;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int finalDiameter = 0;
        diameterOfBinaryTreeDfs (root, finalDiameter);
        return finalDiameter;
        
    }
};