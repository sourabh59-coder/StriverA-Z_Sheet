int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,int>> vec;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qe;
        int ans = 0;
        vector<int> vis(V,0);
        
        qe.push({0,0});
        // vis[0] = 1;
        
        while(!qe.empty())
        {
            auto it = qe.top();
            qe.pop();
            
            int node = it.second;
            int wt = it.first;
            
            if(vis[node])   continue;
            
            vis[node] = 1;
            ans += wt;
            
            for(auto child: adj[node])
            {
                int child_node = child[0];
                int child_wt = child[1];
                
                if(!vis[child_node])
                {
                    qe.push({child_wt,child_node});
                }
            }
        }
        
        return ans;
    }
