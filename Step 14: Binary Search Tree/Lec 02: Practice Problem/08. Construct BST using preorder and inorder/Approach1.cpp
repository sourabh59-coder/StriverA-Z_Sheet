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
        if(is>ie || ps>pe)  return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);

        int i_root = mp[root->val];

        int num = i_root-is;


        TreeNode* leftNode = fun(preorder,ps+1,ps+num,inorder,is,i_root-1,mp);
        TreeNode* rightNode = fun(preorder,ps+num+1,pe,inorder,i_root+1,ie,mp);

        root->left = leftNode;
        root->right = rightNode;

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        int n = inorder.size();

        map<int,int> mp;
        for(int i=0;i<n;i++)    mp[inorder[i]] = i;

        return fun(preorder,0,n-1,inorder,0,n-1,mp);
    }
};
