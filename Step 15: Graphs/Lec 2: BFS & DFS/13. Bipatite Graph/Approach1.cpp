class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        
        vector<int> vis(n,-1);
        queue<int> qe;
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                vis[i] = 0;
                qe.push(i);

                while(!qe.empty())
                {
                    int node = qe.front();
                    qe.pop();
                    int color = vis[node];

                    for(auto it: adj[node])
                    {
                        if(vis[it]==-1)
                        {
                            vis[it] = (!color);
                            qe.push(it);
                        }
                        else
                        {
                            if(vis[it]==color)  return false;
                            else    continue;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
