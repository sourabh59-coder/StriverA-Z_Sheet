class Solution {
public:
    void dfs(vector<vector<int>> adj,int node,vector<int> &vis,bool &ans)
    {
        for(auto it: adj[node])
        {
            if(vis[it]==-1)
            {
                vis[it] = (!vis[node]);
                dfs(adj,it,vis,ans);
            }
            else
            {
                if(vis[it]==vis[node])  ans = false;
                else    continue;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,-1);
        bool ans = true;
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                vis[i] = 0;
                dfs(adj,i,vis,ans);
            }
        }
        
        return ans;
    }
};
