bool isLeaf(Node* root)
    {
        return (!root->left && !root->right);
    }
    void LeftSide(Node* root, vector<int> &ans)
    {
        Node* curr = root->left;
        
        while(curr)
        {
            if(!isLeaf(curr))   ans.push_back(curr->data);
            if(curr->left)      curr = curr->left;
            else                curr = curr->right;
        }
        
    }
    void LeafSide(Node* root,vector<int> &ans)
    {
        if(root==NULL)  return;
        
        if(isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }    
        
        LeafSide(root->left,ans);
        
        LeafSide(root->right,ans);
    }
    void RightSide(Node* root, vector<int> &ans)
    {
        stack<int> st;
        
        Node* curr = root->right;
        
        while(curr)
        {
            if(!isLeaf(curr))   st.push(curr->data);
            if(curr->right)     curr = curr->right;
            else                curr = curr->left;
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL)  return ans;
        
        if(!isLeaf(root))    ans.push_back(root->data);
        
        LeftSide(root,ans);
        
        LeafSide(root,ans);
        
        RightSide(root,ans);
        
        return ans;
    }
