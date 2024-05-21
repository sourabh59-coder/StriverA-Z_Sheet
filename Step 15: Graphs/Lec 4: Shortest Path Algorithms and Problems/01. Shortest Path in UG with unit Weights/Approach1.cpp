class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& v, int n,int m, int src){
        vector<int> adj[n];
        for(int i=0;i<m;i++)
        {
            int u1 = v[i][0];
            int v1 = v[i][1];
            
            adj[u1].push_back(v1);
            adj[v1].push_back(u1);
        }
        vector<int> ans(n,-1);
        vector<int> vis(n,0);
        queue<pair<int,int>> qe;
        vis[src] = 1;
        qe.push({src,0});
        
        while(!qe.empty())
        {
            auto node = qe.front();
            qe.pop();
            
            int ind = node.first;
            int wt = node.second;
            
            ans[ind] = wt;
            
            for(auto it: adj[ind])
            {
                if(!vis[it])
                {
                    vis[it] = 1;
                    qe.push({it,wt+1});
                }
            }
        }
        
        return ans;
    }
};
