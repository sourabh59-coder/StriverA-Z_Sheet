class Solution {
public:
    int fun(TreeNode* root, int &ans)
    {
        if(root==NULL)  return 0;

        int lmax = max(0,fun(root->left,ans));
        int rmax = max(0,fun(root->right,ans));

        ans = max(ans,root->val + lmax + rmax);

        return root->val + max(lmax,rmax);
    }
    int maxPathSum(TreeNode* root) {
        int ans = -1000;
        fun(root,ans);
        return ans;
    }
};
