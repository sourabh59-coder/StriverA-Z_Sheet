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
    void fun(TreeNode* root,int k,bool &ans,unordered_set<int> &st)
    {
        if(root==NULL)  return;

        if(st.count(k - root->val))
        {
            ans = true;
            return;
        }

        st.insert(root->val);

        fun(root->left,k,ans,st);

        fun(root->right,k,ans,st);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        bool ans = false;
        fun(root,k,ans,st);
        return ans;
    }
};
