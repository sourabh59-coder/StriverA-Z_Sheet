vector<int> topView(Node *root)
    {
        //Your code here
        map<int,int> mp;
        queue<pair<Node*, int>> qe;
        
        if(root)    qe.push({root,0});
        
        while(!qe.empty())
        {
            int si = qe.size();
            
            for(int i=0;i<si;i++)
            {
                auto it = qe.front();
                qe.pop();
                
                auto node = it.first;
                int level = it.second;
                
                if(mp.count(level)==0)
                {
                    mp[level] = node->data;
                }
                
                if(node->left)  qe.push({node->left,level-1});
                if(node->right) qe.push({node->right,level+1});
            }
        }
        
        vector<int> ans;
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back(it->second);
        }
        
        return ans;
    }
