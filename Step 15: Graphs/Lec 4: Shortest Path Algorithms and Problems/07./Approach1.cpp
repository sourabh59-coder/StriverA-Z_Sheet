class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flight, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge: flight)
        {
            adj[edge[0]].push_back({edge[1],edge[2]});
            // adj[edge[1]].push_back({edge[0],edge[2]});
        }

        queue<pair<int,pair<int,int>>> qe;

        qe.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src] = 0;

        while(!qe.empty())
        {
            auto it = qe.front();
            qe.pop();

            int node = it.second.first;
            int wt = it.second.second;
            int stop = it.first;

            if(stop==k+1) break;

            for(auto child: adj[node])
            {
                int child_node = child.first;
                int child_wt = child.second;

                if(child_wt + wt < dist[child_node])
                {
                    dist[child_node] = child_wt + wt;
                    qe.push({stop+1 ,{child_node,dist[child_node]}});
                }
            }
        }

        return (dist[dst]!=1e9) ? dist[dst]:-1;
    }
};
