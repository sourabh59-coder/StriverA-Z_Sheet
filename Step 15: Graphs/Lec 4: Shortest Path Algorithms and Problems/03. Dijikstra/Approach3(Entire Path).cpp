vector<int> shortestPath(int n, int m, vector<vector<int>>& v) {
        vector<int> ans(n+1,1e9);
        vector<int> path(n+1);
        for(int i=1;i<=n;i++)
        {
            path[i] = i;
        }
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<m;i++)
        {
            int u1 = v[i][0];
            int v1 = v[i][1];
            int wt = v[i][2];
            
            adj[u1].push_back({v1,wt});
            adj[v1].push_back({u1,wt});
        }
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qe;
        
        qe.push({0,1});
        ans[1] = 0;
        
        while(!qe.empty())
        {
            auto it = qe.top();
            qe.pop();
            
            int node = it.second;
            int wt = it.first;
            
            for(auto child: adj[node])
            {
                int child_node = child.first;
                int child_wt = child.second;
                
                if(child_wt + wt < ans[child_node])
                {
                    ans[child_node] = child_wt+wt;
                    path[child_node] = node;
                    qe.push({ans[child_node],child_node});
                }
            }
        }
        if(ans[n]==1e9) return {-1};
        
        vector<int> final;
        
        int dest = n;
        while(dest != path[dest])
        {
            final.push_back(dest);
            dest = path[dest];
        }
        final.push_back(dest);
        final.push_back(ans[n]);
        reverse(final.begin(),final.end());
        
        // for(int i=0;i<final.size();i++) cout<<final[i]<<" ";
        // cout<<endl;
        
        return final;
    }
