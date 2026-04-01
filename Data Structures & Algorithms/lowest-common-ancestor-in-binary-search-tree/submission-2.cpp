/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestorUtil (TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if ((root -> val >= p -> val && root -> val <= q -> val) || (root -> val >= q -> val && root -> val <= p -> val)) return root;
        if (root -> val > p -> val && root -> val > q -> val) return lowestCommonAncestorUtil (root -> left, p, q);
        return lowestCommonAncestorUtil (root -> right, p, q);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lowestCommonAncestorUtil (root, p, q);
    }
};