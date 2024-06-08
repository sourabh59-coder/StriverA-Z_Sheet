/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void fun(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mp)
    {
        if(root==NULL)  return;

        TreeNode* par = root;

        if(root->left)
        {
            mp[root->left] = par;
            fun(root->left,mp);
        }

        if(root->right)
        {
            mp[root->right] = par;
            fun(root->right,mp);
        }
    }
    vector<TreeNode*> fun1(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp)
    {
        vector<TreeNode*> ans;

        while(root!=mp[root])
        {
            ans.push_back(root);
            root = mp[root];
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> mp;
        fun(root,mp);
        
        vector<TreeNode*> vp = fun1(p,mp);
        vector<TreeNode*> vq = fun1(q,mp);

        TreeNode* ans;
        int size = min(vp.size(),vq.size());

        for(int i=0;i<size;i++)
        {
            if(vq[i]==vp[i])    ans = vq[i];
        }

        return ans;
    }
};
