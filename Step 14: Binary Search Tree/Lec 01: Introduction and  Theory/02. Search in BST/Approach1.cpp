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
    void fun(TreeNode* root,int v,TreeNode* &ans)
    {
        if(root==NULL)  return;

        if(root->val==v)
        {
            ans = root;
            return;
        }

        fun(root->left,v,ans);
        fun(root->right,v,ans);
    }
    TreeNode* searchBST(TreeNode* root, int v) {
        TreeNode* ans = NULL;
        fun(root,v,ans);
        return ans;
    }
};
