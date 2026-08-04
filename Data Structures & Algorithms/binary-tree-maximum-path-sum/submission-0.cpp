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
    int findMaxSum(TreeNode* root, int &res)
    {
        if(root == nullptr)
            return 0;
        
        int leftSum = max(0,findMaxSum(root->left,res));
        int rightSum = max(0, findMaxSum(root->right,res));

        res = max(res, leftSum + rightSum + root->val);

        return root->val + max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int res = root->val;
        findMaxSum(root,res);
        return res;
    }
};
