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
    void fun(TreeNode* p,TreeNode* q,bool &ans)
    {
        if(p==NULL && q==NULL)  return;
        if(p==NULL && q!=NULL)
        {
            ans = false;
            return;
        }
        if(q==NULL && p!=NULL)
        {
            ans = false;
            return;
        }

        if(p->val==q->val)
        {
            fun(p->left,q->right,ans);
            fun(p->right,q->left,ans);
        }
        else
        {
            ans = false;
            return;
        }
    }
    bool isSymmetric(TreeNode* root) {
        bool ans = true;
        if(root)    fun(root->left,root->right,ans);
        return ans;
    }
};
