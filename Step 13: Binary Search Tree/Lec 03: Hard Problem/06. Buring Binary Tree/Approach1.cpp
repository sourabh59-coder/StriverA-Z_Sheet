void fun(Node *root, vector<vector<int>> &adj)
    {
        if(root==NULL)  return;
        
        int a = root->data;
        
        if(root->left)
        {
            int b = root->left->data;
            adj[a].push_back(b);
            adj[b].push_back(a);
            fun(root->left,adj);
        }
        
        if(root->right)
        {
            int b = root->right->data;
            adj[a].push_back(b);
            adj[b].push_back(a);
            fun(root->right,adj);
        }
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        vector<vector<int>> adj(100001);
        fun(root,adj);
        int ans = -1;
        queue<int> qe;
        vector<int> vis(100001,0);
        qe.push(target);
        vis[target] = 1;
        
        while(!qe.empty())
        {
            ans++;
            int si = qe.size();
            
            for(int i=0;i<si;i++)
            {
                int node = qe.front();
                qe.pop();
                
                for(auto child: adj[node])
                {
                    if(!vis[child])
                    {
                        vis[child] = 1;
                        qe.push(child);
                    }
                }
            }
        }
        
        return ans;
    }
