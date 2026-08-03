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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;

        int countLeft = maxDepth(root->left);
        int countRight = maxDepth(root->right);
        int maxDepthVal = max(countLeft,countRight);
        return 1 + maxDepthVal;
    }
};
