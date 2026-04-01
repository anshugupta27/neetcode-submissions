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
    int maxPathSum (TreeNode* root, int &maxPathSumVal) {
        if (!root) return 0;
        int leftSum = maxPathSum (root -> left, maxPathSumVal);
        int rightSum = maxPathSum (root -> right, maxPathSumVal);
        maxPathSumVal = max ({maxPathSumVal, leftSum + root -> val, rightSum + root -> val, root -> val, leftSum+rightSum+root->val});
        return max ({max(leftSum, rightSum) + root -> val, root -> val});
    }

    int maxPathSum(TreeNode* root) {
        int maxPathSumVal= INT_MIN;
        maxPathSum (root, maxPathSumVal);
        return maxPathSumVal;
    }
};