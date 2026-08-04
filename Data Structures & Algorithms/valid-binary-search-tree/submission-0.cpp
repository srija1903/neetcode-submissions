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
    TreeNode *prev = nullptr;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        if(!isValidBST(root->left))
            return false;
        
        // 3. PROCESS CURRENT NODE:
        // Is current value strictly greater than prev->val?
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }
        prev = root; // Update prev to current node

        // 4. Recurse RIGHT
        return isValidBST(root->right);
    }
};
