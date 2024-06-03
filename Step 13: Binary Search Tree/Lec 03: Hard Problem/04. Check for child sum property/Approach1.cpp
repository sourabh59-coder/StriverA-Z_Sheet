void fun(Node* root,int &ans)
    {
        if(root==NULL)  return;
        
        if(root->left==NULL && root->right==NULL)   return;
        
        int  val = 0;
        
        if(root->left)
        {
            val += root->left->data;
            fun(root->left,ans);
        }
        
        if(root->right)
        {
            val += root->right->data;
            fun(root->right,ans);
        }
        
        if(val!=root->data)
        {
            ans = 0;
            return;
        }
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
     int ans = 1;
     fun(root,ans);
     return ans;
    }
