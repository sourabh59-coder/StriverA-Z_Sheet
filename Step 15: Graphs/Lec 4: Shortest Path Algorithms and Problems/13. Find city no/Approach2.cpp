class Solution {
public:
    void Dijkstra(vector<vector<pair<int,int>>> &adj, int start, int n, int &city_no, int &count, int thres) {
        vector<int> dist(n, 1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qe;

        qe.push({0, start});
        dist[start] = 0;

        while(!qe.empty()) {
            auto it = qe.top();
            qe.pop();

            int node = it.second;
            int wt = it.first;

            for(auto &child : adj[node]) {
                int child_node = child.first;
                int child_wt = child.second;

                if(child_wt + wt < dist[child_node]) {
                    dist[child_node] = child_wt + wt;
                    qe.push({dist[child_node], child_node});
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(i != start && dist[i] <= thres) {
                cnt++;
            }
        }

        if(cnt <= count) {
            count = cnt;
            city_no = start;
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int thres) {
        int city_no = -1;
        int count = n;

        vector<vector<pair<int,int>>> adj(n);

        for(auto &edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        for(int i = 0; i < n; i++) {
            Dijkstra(adj, i, n, city_no, count, thres);
        }

        return city_no;
    }
};
