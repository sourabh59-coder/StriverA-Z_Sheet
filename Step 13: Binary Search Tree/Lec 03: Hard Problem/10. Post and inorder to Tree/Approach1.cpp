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
    TreeNode* fun(vector<int> &postorder,int ps,int pe,vector<int> &inorder,int is,int ie,map<int,int> &mp)
    {
        if(ps>pe || is>ie)  return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int i_root = mp[root->val];

        int num = i_root - is;

        TreeNode* left_node = fun(postorder,ps,ps+num-1,inorder,is,i_root-1,mp);

        TreeNode* right_node = fun(postorder,ps+num,pe-1,inorder,i_root+1,ie,mp);

        root->left = left_node;
        root->right = right_node;

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }

        return fun(postorder,0,n-1,inorder,0,n-1,mp);
    }
};
