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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 && inorder.size() == 0)
            return nullptr;
        
        int size1 = preorder.size();
        int size2 = inorder.size();

        // The 1st element of pre order is the root and the 2nd element of inorder is the root
        TreeNode *root = new TreeNode(preorder[0]);
        
        stack<TreeNode*> st;
        st.push(root);
        int j=0;
        for(int i=1;i<preorder.size();i++)
        {
            TreeNode *curr;
            curr = st.top();
                // Get the left element down
                if(curr->val != inorder[j])
                {
                    curr->left = new TreeNode(preorder[i]);
                    st.push(curr->left);
                }
                else
                {
                    TreeNode *lastPopped = nullptr;
                    while(!st.empty() && (st.top()->val == inorder[j]))
                    {
                        lastPopped = st.top();
                        st.pop();
                        j++;
                    }

                    // Attach as right child of the last popped ancestor
                    lastPopped->right = new TreeNode(preorder[i]);
                    st.push(lastPopped->right);
                }
        }
        return root;
    }
};
