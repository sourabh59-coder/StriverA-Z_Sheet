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
    void fun(TreeNode* root,int &cnt)
    {
        if(root==NULL)  return;

        cnt++;

        fun(root->right,cnt);

        fun(root->left,cnt);
    }
    int countNodes(TreeNode* root) {
        int cnt = 0;
        fun(root,cnt);
        return cnt;
    }
};
