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
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            // 1. Push all left children to reach the smallest unvisited element
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // 2. Pop the current smallest element
            curr = st.top();
            st.pop();

            // 3. Decrement k
            k--;
            if (k == 0) {
                return curr->val; // Found the kth smallest!
            }

            // 4. Move to the right child
            curr = curr->right;
        }

        return -1;
    }
};
