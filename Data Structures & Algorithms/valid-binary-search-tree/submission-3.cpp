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
    bool isValidBSTUtil (TreeNode* root, TreeNode* &prev) {
        if (!root) return true;
        if (!isValidBSTUtil (root -> left, prev)) return false;
        if (prev) {
            if (prev -> val >= root -> val) return false;
        }
        prev = root;
        if(!isValidBSTUtil (root -> right, prev)) return false;
        return true;

    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return isValidBSTUtil (root, prev);
        
    }
};