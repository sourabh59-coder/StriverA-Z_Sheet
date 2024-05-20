void dfs(vector<int> adj[],int node,vector<int> &vis,stack<int> &st)
	{
	    vis[node] = 1;
	    
	    for(auto it: adj[node])
	    {
	        if(!vis[it])    dfs(adj,it,vis,st);
	    }
	    
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int> vis(V,0);
	    stack<int> st;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(adj,i,vis,st);
	        }
	    }
	    
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
