void fun(Node* root, vector<vector<int>> &ans,vector<int> &vec)
    {
        if(root->left==NULL && root->right==NULL)
        {
            vec.push_back(root->data);
            ans.push_back(vec);
            vec.pop_back();
            return;
        }
        
        vec.push_back(root->data);
        
        if(root->left)    fun(root->left,ans,vec);
        
        if(root->right)   fun(root->right,ans,vec);
        
        vec.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> vec;
        if(root)    fun(root,ans,vec);
        return ans;
    }
