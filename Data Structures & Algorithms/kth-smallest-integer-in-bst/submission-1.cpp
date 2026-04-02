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
    void kthSmallestUtil (TreeNode* root, int &k, TreeNode* &kthSmallest) {
        if (!root) return;
        kthSmallestUtil (root -> left, k, kthSmallest);
        k--;
        if (k == 0) {
            kthSmallest = root;
        }
        kthSmallestUtil (root -> right, k, kthSmallest);

    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* kthSmallest = NULL;
        if (!root) return -1;
        kthSmallestUtil (root, k, kthSmallest);
        return kthSmallest ? kthSmallest -> val : -1;
    }
};