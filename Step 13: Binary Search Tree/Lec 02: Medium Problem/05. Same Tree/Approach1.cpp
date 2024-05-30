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
    void fun(TreeNode* p,TreeNode* q,bool &flag)
    {
        if((!p && !q))
        {
            return;
        }
        if((p && q))
        {
            if(p->val == q->val)
            {
                fun(p->left,q->left,flag);
                fun(p->right,q->right,flag);
            }
            else
            {
                flag = false;
                return;
            }
        }
        else
        {
            flag = false;
            return;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = true;
        fun(p,q,ans);
        return ans;
    }
};
