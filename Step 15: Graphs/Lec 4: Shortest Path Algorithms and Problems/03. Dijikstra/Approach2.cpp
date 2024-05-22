vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> st;
        vector<int> ans(V,1e9);
        
        ans[S] = 0;
        st.insert({0,S});
        
        while(!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int wt = it.first;
            st.erase(it);
            
            for(auto child: adj[node])
            {
                int child_node = child[0];
                int child_wt = child[1];
                
                if(child_wt + wt < ans[child_node])
                {
                    if(ans[child_node]!=1e9)    st.erase({ans[child_node],child_node});
                    
                    ans[child_node] = child_wt + wt;
                    st.insert({ans[child_node],child_node});
                }
            }
        }
        
        return ans;
    }
