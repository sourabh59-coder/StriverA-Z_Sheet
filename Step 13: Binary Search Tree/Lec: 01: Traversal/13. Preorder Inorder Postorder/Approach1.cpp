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
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    stack<pair<TreeNode*,int>> st;

    if(root)    st.push({root,1});
    vector<int> pre,ino,post;

    while(!st.empty())
    {
        auto it = st.top();
        st.pop();

        auto node = it.first;
        int val = it.second;

        if(val==1)
        {
            pre.push_back(node->data);
            val++;
            st.push({node,val});

            if(node->left)  st.push({node->left,1});
        }
        else if(val==2)
        {
            ino.push_back(node->data);
            val++;
            st.push({node,val});

            if(node->right) st.push({node->right,1});
        }
        else
        {
            post.push_back(node->data);
        }
    }

    vector<vector<int>> ans;
    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(post);

    return ans;
}
