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
    void inorder(TreeNode* root,TreeNode* &left,TreeNode* &middle,TreeNode* &right,TreeNode* &prev)
    {
        if(root==NULL)  return;

        inorder(root->left,left,middle,right,prev);

        if(prev!=NULL && prev->val > root->val)
        {
            if(left==NULL)
            {
                left = prev;
                middle = root;
            }
            else    right = root;
        }

        prev = root;

        inorder(root->right,left,middle,right,prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* leftv = NULL, *middle = NULL, *rightv = NULL;
        TreeNode* prev = NULL;

        inorder(root,leftv,middle,rightv,prev);

        if(leftv && rightv)   swap(leftv->val,rightv->val);
        else if(leftv && middle) swap(leftv->val,middle->val);
    }
};
