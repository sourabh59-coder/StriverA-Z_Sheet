class Solution {
public:
    int countPaths(int n, vector<vector<int>>& edges) {
        int start = 0;
        int dest = n-1;
        int mod = (int)(1e9+7);

        vector<vector<pair<long long,long long>>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        vector<long long> dist(n,LLONG_MAX);
        vector<long long> cnt(n,0);

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>>> qe;
        cnt[start] = 1;
        dist[start] = 0;
        qe.push({0,start});

        while(!qe.empty())
        {
            auto it = qe.top();
            qe.pop();

            long long node = it.second;
            long long wt = it.first;
            long long count = cnt[node]%mod;

            if(node==dest)   return (int)count;

            for(auto child: adj[node])
            {
                long long child_node = child.first;
                long long child_wt = child.second;

                if(child_wt==LLONG_MAX || wt==LLONG_MAX)    continue;
                long long cal = child_wt + wt;
                if(dist[child_node] == cal)
                {
                    long long val = (cnt[child_node] + cnt[node]) % mod;
                    cnt[child_node] = val;
                }

                else if(dist[child_node] > child_wt + wt)
                {
                    dist[child_node] = child_wt + wt;
                    cnt[child_node] = cnt[node] % mod;
                    qe.push({dist[child_node],child_node});
                }
            }
        }

        return -1;
    }
};
