vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans(V+1,1e9);
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qe;
        
        ans[S] = 0;
        qe.push({ans[S],S});
        
        while(!qe.empty())
        {
            auto node = qe.top();
            qe.pop();
            
            int ind = node.second;
            int wt = node.first;
            
            for(auto it: adj[ind])
            {
                int child_wt = it[1];
                int child_ind = it[0];
                
                if(child_wt + wt < ans[child_ind])
                {
                    ans[child_ind] = child_wt + wt;
                    qe.push({ans[child_ind],child_ind});
                }
            }
        }
        
        return ans;
    }
