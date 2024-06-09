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
    TreeNode* minValued(TreeNode* root)
    {
        TreeNode* temp = root;
        while(temp->left!=NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)  return NULL;

        if(root->val < key) root->right = deleteNode(root->right, key);

        else if(root->val > key)    root->left = deleteNode(root->left, key);

        else
        {
            if(root->right==NULL && root->left==NULL)   root = NULL;
            else if(root->right==NULL)  root = root->left;
            else if(root->left==NULL)   root = root->right;
            else if(root->right!=NULL && root->left!=NULL)
            {
                TreeNode* temp = minValued(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right,temp->val);
            }
        }

        return root;
    }
};
