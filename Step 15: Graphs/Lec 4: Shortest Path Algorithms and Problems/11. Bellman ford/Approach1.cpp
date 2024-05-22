vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> vis(V,1e8);
        vis[S] = 0;
        for(int i=0;i<V-1;i++)
        {
            for(auto it: edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(vis[u]!=1e8 && vis[u]+wt < vis[v])   vis[v] = wt+vis[u];
            }
        }
        
        for(auto it: edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(vis[u]!=1e8 && vis[u]+wt < vis[v])   return {-1};
        }
        
        return vis;
    }
