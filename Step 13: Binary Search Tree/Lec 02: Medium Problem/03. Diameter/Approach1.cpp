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
    void fun(TreeNode* root,unordered_map<TreeNode*,int> &depth,int &ans)
    {
        if(root==NULL)  return;

        depth[root] = 0;

        int value = 0;

        fun(root->left, depth, ans);
        fun(root->right, depth, ans);

        if(root->left)
        {
            depth[root] = max(depth[root], depth[root->left]+1);
            value += depth[root->left] + 1;
        }

        if(root->right)
        {
            depth[root] = max(depth[root], depth[root->right]+1);
            value += depth[root->right] + 1;
        }

        ans = max(ans,value);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*,int> depth;
        int ans = 0;
        fun(root,depth,ans);
        return ans;
    }
};
