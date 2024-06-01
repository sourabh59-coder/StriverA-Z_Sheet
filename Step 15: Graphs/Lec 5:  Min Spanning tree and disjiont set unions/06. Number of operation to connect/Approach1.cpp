class Solution {
public:
    void dfs(vector<int> adj[],int node,vector<int> &vis)
    {
        vis[node] = 1;

        for(auto child: adj[node])
        {
            if(!vis[child])
            {
                dfs(adj,child,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& v) {
        if(v.size() < n-1)  return -1;
        vector<int> adj[n];
        for(int i=0;i<v.size();i++)
        {
            int x = v[i][0];
            int y = v[i][1];

            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(adj,i,vis);
            }
        }
        return cnt-1;
    }
};
