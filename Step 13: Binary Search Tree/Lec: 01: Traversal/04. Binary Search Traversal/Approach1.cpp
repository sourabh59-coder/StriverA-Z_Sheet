/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/


void Preorder(TreeNode* root, vector<int> &ans)
{
    if(root==NULL)  return;

    ans.push_back(root->data);

    Preorder(root->left,ans);

    Preorder(root->right,ans);
}

void Postorder(TreeNode* root, vector<int> &ans)
{
    if(root==NULL)  return;

    Postorder(root->left,ans);

    Postorder(root->right, ans);

    ans.push_back(root->data);
}


void Inorder(TreeNode* root, vector<int> &v)
{
    if(root==NULL)  return;

    Inorder(root->left,v);

    v.push_back(root->data);

    Inorder(root->right,v);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> pre, post, ino;

    vector<vector<int>> ans;

    Preorder(root,pre);

    Postorder(root,post);

    Inorder(root,ino);

    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(post);

    return ans;

}
