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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* ptr = new TreeNode(val);
        if(root==NULL)
        {
            root = ptr;
        }
        TreeNode* temp = root;
        if(temp->val < val)
        {
            if(temp->right==NULL)   temp->right = ptr;
            else                    insertIntoBST(temp->right,val);
        }
        else if(temp->val > val)
        {
            if(temp->left==NULL)    temp->left = ptr;
            else                    insertIntoBST(temp->left,val);
        }

        return root;
    }
};
