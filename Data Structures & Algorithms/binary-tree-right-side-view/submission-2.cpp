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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue <TreeNode*> levelOrderQueue;
        levelOrderQueue.push (root);
        vector<int> finalAns;
        while (levelOrderQueue.size()) {
            int size = levelOrderQueue.size();
            int lastNode;
            while (size--) {
                TreeNode* front = levelOrderQueue.front();
                lastNode = front -> val;
                levelOrderQueue.pop();
                if (front -> left) {
                    levelOrderQueue.push (front -> left);
                }
                if (front -> right ) {
                    levelOrderQueue.push (front -> right);
                }
            }
             finalAns.push_back (lastNode);
           
        }
        return finalAns;
    }
};