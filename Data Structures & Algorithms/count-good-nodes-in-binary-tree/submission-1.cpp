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
    void goodNodes (TreeNode* root, int maxUptil, int &goodNodeCounter) {
        if (!root) return ;
        if (root -> val >= maxUptil) goodNodeCounter++;
        maxUptil = max(maxUptil, root -> val);
        goodNodes (root -> left, maxUptil, goodNodeCounter);
        goodNodes (root -> right, maxUptil, goodNodeCounter);

    }
    int goodNodes(TreeNode* root) {
        // store in each iteration the max in the path
        int goodNodeCounter = 0, maxUptil = INT_MIN;
        goodNodes (root, maxUptil, goodNodeCounter);
        return goodNodeCounter;
    }
};