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
    TreeNode* fun(vector<int> &preorder,int ps,int pe,vector<int> &inorder,int is,int ie,map<int,int> &mp)
    {
        if(ps>pe || is>ie)  return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);

        int i_root = mp[root->val];
        int num = i_root-is;

        TreeNode* left_node = fun(preorder,ps+1,ps+num,inorder,is,i_root-1,mp);
        TreeNode* right_node = fun(preorder,ps+num+1,pe,inorder,i_root+1,ie,mp);

        root->left = left_node;

        root->right = right_node;

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        int n = preorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }

        return fun(preorder,0,n-1,inorder,0,n-1,mp);
    }
};
