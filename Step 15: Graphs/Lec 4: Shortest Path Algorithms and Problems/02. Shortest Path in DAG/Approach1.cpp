void dfs(vector<pair<int,int>> adj[],int node,vector<int> &vis,stack<int> &st)
  {
      vis[node] = 1;
      
      for(auto it: adj[node])
      {
          int child_node = it.first;
          int child_wt = it.second;
          
          if(!vis[child_node])  dfs(adj,child_node,vis,st);
      }
      
      st.push(node);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        stack<int> st;
        vector<int> vis(N,0);
        vector<pair<int,int>> adj[N];
        
        for(int i=0;i<M;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
            {
                dfs(adj,i,vis,st);
            }
        }
        
        // while(!st.empty())
        // {
        //     cout<<st.top()<<" ";
        //     st.pop();
        // }
        // cout<<endl;
        
        vector<int> ans(N,1e9);
        
        queue<pair<int,int>> qe;
        qe.push({0,0});
        ans[0] = 0;
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            int wt = ans[node];
            
            for(auto child: adj[node])
            {
                int child_node = child.first;
                int child_wt = child.second;
                
                if(child_wt + wt < ans[child_node])
                {
                    ans[child_node] = child_wt + wt; 
                }
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(ans[i]==1e9) ans[i] = -1;
        }
        
        return ans;
    }
